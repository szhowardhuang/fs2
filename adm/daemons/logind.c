// �иĹ�, �����������ִ���̫���֮���Զ�����
// fixed by wade Thu Sep 28 1995
// fixed by wade ���� okip, check passwd ���� 12/11/1995
// ���� sleep ���� by wade 87/8/11.

// 1999.11.16 by Server
// ������� loginwaitd.c �ļ��
// destruct() -> void new_destruct(object ob);

//ʹ���µ��ż�֪ͨϵͳby bss
//����ʽ��/adm/daemons/cmaild.c��

#include <net/socket.h>
#include <socket_err.h>
#include <globals.h>
#include <ansi.h>
#include <command.h>
#include <limit.h>
#include <login.h>


#define LOCK "/include/lock.h"
#define RELOG_IP "/adm/daemons/relog_ip.c"

inherit F_DBASE;

int wizlocklevel=0;

string *banned_name = ({
  "��", "��", "��", "��", "��", "��", "��",
  "�������", "���й�", "��ʦ", "�ϵ�", "����", "���","��ķ","�ػ�",
});

// ���ֲ��ܺ�������������ĳ����
string *banned_id = ({
  "fuck", "shit", "wizard", "god", "wiz","gy","corpse",
});
mapping gift = ([
  "str":"����",
  "cor":"��ʶ",
  "int":"����",
  "spi":"����",
  "cps":"����",
  "per":"��ò",
  "con":"����",
  "kar":"��Ե",
  ]);

mapping day2num =([
  "Mon"   : 1,
  "Tue"   : 2,
  "Wed"   : 3,
  "Thu"   : 4,
  "Fri"   : 5,
  "Sat"   : 6,
  "Sun"   : 7
]);

string *ok_ip = ({
"140.117.201.101",
"192.192.35.241",
"192.192.35.242",
"211.75.78.241",
"211.75.78.81", // sm2
});

mapping attrs=([
    "str"  :  "����",
    "cps"  :  "����",
    "int"  :  "����",
    "cor"  :  "��ʶ",
    "con"  :  "����",
    "spi"  :  "����",
    "per"  :  "��ò",
    "kar"  :  "��Ե",
]);

mapping nattr=([
    "str"  :  "cps",
    "cps"  :  "int",
    "int"  :  "cor",
    "cor"  :  "con",
    "con"  :  "spi",
    "spi"  :  "per",
    "per"  :  "kar",
]);

mapping blocks  = ([]);

// by konn ����ȷ��ʱ�任�����
int thistime, nowtime, player_day, player_week, day;
int nowhour;

void get_points (string points, object ob, object user, int tp, string attr, int i);
void get_id(string arg, object ob, int times);
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
void new_destruct(object ob);
void get_ctrlc(string str, object ob, int count);
string str, my_ip, ip1, ip2, ip3, ip4, ipp1, ipp2, ipp3, ipp4;
void create()
{
  seteuid(getuid());
  set_temp("channel_id", "���߾���");
}

// by konn
int query_time()
{
  return time();
}

/*
// by konn
void key_generator(object ob)
{
  int i, v, *save_keys;

  save_keys = ({});
  for(i = 0 ; i < 5; i++) {
    do {
      v = random(26) + 1;
    }
    while( v == 8 );
    save_keys += ({ v });
  }
  save_keys += ({ 3 });
  ob->set_temp("keys", save_keys);
}
*/

// logon --> logonn
void logon(object ob)
{
  object *usr;
  string str;
  int i, t, wiz_cnt, ppl_cnt, login_cnt, *save_keys,time;

  // by konn
  if(CBIP_D->check_ip(ob))
  {
  write("�Բ��𣬴� IP Ŀǰ�ѱ�ͣ�á�\n");
  new_destruct (ob);
  return;
  }
  time=0;
  if(time=RELOG_IP->check_ip(ob))
  {
  write("�Բ��𣬴� IP Ŀǰ�ѱ�ͣ�á�\n");
  printf("��Ҫ�ȵ� %s �ſ������ߡ�\n",ctime(time));
  destruct(ob);
  return ;
  }

  cat(WELCOME, 1);
  UPTIME_CMD->main();

  if (file_size ("/include/lock.h") > 0) {
    if (sscanf (read_file (LOCK), "%d", wizlocklevel) != 1) {
      log_file ("/log", LOCK+ " format error!\n");
    }
  }

  usr = users();
  wiz_cnt = 0;
  ppl_cnt = 0;
  login_cnt = 0;
  for(i=0; i<sizeof(usr); i++) {
    if( !environment(usr[i]) ) {
      if( interactive(usr[i]) )
  login_cnt++;
      else
  destruct(usr[i]);
    }
    else if( wizardp(usr[i]) ) wiz_cnt++;
    else if( !usr[i]->query_temp("netdead") ) ppl_cnt++;
  }
#ifdef MAX_USERS
  if(file_size("/data/player") >0){
    sscanf( read_file("data/player", 1, 1 ), "%d %d %d", player_week, player_day, day );
    printf("���������˴�: "HIG"%d"NOR", ���������˴�: "HIY"%d"NOR" ��\n", player_day, player_week );
  }
  // konn..
  nowtime = (time() + 28800) % 86400;
  if( nowtime > 28800 ) {
  printf("��ʱ����������Ϊ "+HIM+MAX_USERS+NOR" ��, ���Ϲ��� "HIC"%d"NOR" λ���, �Լ� "HIR"%d"NOR" λʹ���߳��������С�\n",
    ppl_cnt, login_cnt );
  }
  else {
  printf("��ʱ����������Ϊ "+HIM+MAX_USERS_2+NOR" ��, ���Ϲ��� "HIC"%d"NOR" λ���, �Լ� "HIR"%d"NOR" λʹ���߳��������С�\n",
    ppl_cnt, login_cnt );
  }
#else
  if(file_size("/data/player") >0){
    sscanf (read_file("data/player", 1, 1 ), "%d %d %d",
            player_week, player_day, day );
    printf ("���������˴�: "HIG"%d"NOR", ���������˴�: "HIY"%d"NOR
           ", ���� "HIC"%d"NOR", �Լ� "HIR"%d"NOR" λʹ���������С�\n",
           player_day, player_week, ppl_cnt, login_cnt);
  }
#endif


  // by ACKY
  if( blocks[query_ip_number(ob)] > time() ) {
    write("�����������ԣ������Ժ������ߡ�\n");
    new_destruct(ob);
    return;
  }
  CHANNEL_D->do_channel( this_object(), "sys", sprintf("(%s) IP:%-15s ���������С�",
    ctime(time())[4..15],query_ip_number()) );

  printf( HIY"������λַ %s ������, ��ӭ��������ռ䡣\n"NOR, query_ip_number() );
  write("����������Ӣ�����ֻ���(guest)�ʺŲι�: ");
  input_to( (: get_id :), ob, 1 );
}

// by konn  ȡ��ctrl key ��ֵ
/*
void get_ctrlc(string str, object ob, int count)
{
  string *chars;
  int size, i, *save_keys;
  chars = ({ str });
  if( port_23[ob->query_temp("ip")] == 1 ) {
    map_delete(port_23, (ob->query_temp("ip")+" 23"));
    write("\n���޷��ô���������!\n");
    new_destruct(ob);
    return ;
  }
  ob->delete_temp("ip");
  if( (chars[0][0] == 27
    &&  chars[0][1] == 91
    &&  chars[0][2] == 65)
    || (chars[0][0] == 27
    &&  chars[0][1] == 91
    &&  chars[0][2] == 53
    &&  chars[0][3] == 126) ) {
      ob->delete_temp("keys");
      ob->delete_temp("kick");
      write("\n"+ob->query("id")+" �Ѿ�ע�����, ���������룺");
      input_to("get_passwd", 1, ob);
      return ;
    }
    else {
      write("\n�ܱ�Ǹ����ʹ�÷Ƿ����߳�ʽ���Զ�������...\n");
      new_destruct(ob);
      return ;
    }
}
*/
// by konn
/*
void port_23_test(int sock, mixed str)
{
  string addr = socket_address(sock);
  if( addr[strlen(addr)-3] == ' ' )
    port_23[addr[0..strlen(addr)-4]] = 1;
  if( addr[strlen(addr)-4] == ' ' )
    port_23[addr[0..strlen(addr)-5]] = 1;
  socket_close(sock);
}
*/
// Ϊ��Ҫ����̫���֮���ܹ�����, ������һ������ times
// void get_id(string arg, object ob)
// �����ط��Ĳ����޸Ĳ�����һһ�г�
// fixed by wade Thu Sep 28 1995
void get_id(string arg, object ob, int times)
{
  int all_players=0, all_wizs=0, i, max_users;
  int *save_keys, sock, sock2, sock3, sock4, sock5, ok = 0;
  object *all_user;
  object  ppl,user;
  object  *user_a;

  arg = lower_case(arg);
  if( !check_legal_id(arg)) {
    // ������� if ��Ϊ��Ҫ����̫���֮���ܹ�����
    // fixed by wade Thu Sep 28 1995
    if (times >= 3) {
      write ("�Բ���, ������̫����ˡ�\n");
      new_destruct (ob);
      return;
    }
    write("����Ӣ�����֣�");
    input_to("get_id", ob, times+1);
    return;
  }

//
//
//
/*
  if( SECURITY_D->get_status(arg) == "(player)" ) {
      new_destruct(ob);
      return;
  }
*/
#ifdef MAX_USERS
/*
  for(all_user=users(), i=0; i<sizeof(all_user); i++)
     if( !wizardp(all_user[i]) && all_user[i]->query("id") && interactive(all_user[i]) )
   all_players++;
     else if( wizardp(all_user[i]) && all_user[i]->query("id") )
   all_wizs++;
*/

  all_user = users();
  all_wizs = 0;
  all_players = 0;
  for(i=0; i<sizeof(all_user); i++) {
    if( !environment(all_user[i]) ) {
      if( !interactive(all_user[i]) )
  destruct(all_user[i]);
    }
    else if( wizardp(all_user[i]) ) all_wizs++;
    else if( !all_user[i]->query_temp("netdead") ) all_players++;
  }

  map_delete( blocks, query_ip_number(ob) );
  ob->set( "id", arg );

  nowtime = (time() + 28800) % 86400;
  if( nowtime > 28800 )
    max_users = MAX_USERS;
  else
    max_users = MAX_USERS_2;

  if (all_players >= max_users) {

    if( ""+SECURITY_D->get_status(arg)=="(player)" || arg == "guest")
    {
    write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ������������\n");
    new_destruct(ob);
    return;
    }
    if (all_wizs >= 7 &&
    ""+SECURITY_D->get_status(arg)!="(admin)" &&
    ""+SECURITY_D->get_status(arg)!="(manager)" &&
    ""+SECURITY_D->get_status(arg)!="(guest)" &&
    ""+SECURITY_D->get_status(arg)!="(arch)")
    {
      write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ������������\n");
      new_destruct(ob);
      return;
    }
  }
#endif

  if( !BANMULTI_D->ban_multi(ob) )
  {
    printf("�Բ���Ŀǰ�� IP ����֮������������Ѷ�����\n");
    new_destruct(ob);
    return;
  }

  if( (string)ob->set("id", arg) != arg ) {
    write("Failed setting user name.\n");
    new_destruct(ob);
    return;
  }

  if( arg=="guest" ) {
    if ( wizlocklevel > 0) {
#ifdef WIZ_LOCK
  write (HIY+WIZ_LOCK+NOR);
#else
  write (HIY+"ϵͳ��ֹ�� login, sorry.\n"+NOR);
#endif
  destruct(ob);
  return;
    }
    if (user=find_player("guest"))
      if (interactive(user)) {
  write( "�Բ���, ����һλ guest ��������ˡ�\n" );
  new_destruct (ob);
  return;
      }
      else new_destruct (user);
    // If guest, let them create the character.
    ob->set("name", "���ع�·��");
    ob->set("password", crypt("guest",0) );
    ob->set("body", USER_OB);
    user = make_body(ob);
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
    user->set("gender", "����");
    write("\n��ӭ�ιۿ���ռ䡣\n");
    enter_world(ob, user);
    return;
  }
  else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
    if( ob->restore() ) {
  // by konn
  // mark by bss,����ֱ����ip,���Թ���վ���õ�
/*
  nowtime = (time() + 28800) % 86400;
  if( SECURITY_D->get_status(arg) == "(player)" && nowtime > 28800 ) {
    if( (sock2 = socket_create(STREAM, "", "")) > 0
    &&  socket_connect(sock2, query_ip_name()+" 23","port_23_test","")>0){
      for (ok=0, i=0; i<sizeof(ok_ip); i++) {
        if (strsrch(query_ip_number(ob), ok_ip[i]) == 0)
    ok = 1;
      }

      if( !ok ) {
        socket_write(sock2, "test!\n");
        ob->set_temp("ip", query_ip_number(ob));
      }
    }

    if( (sock3 = socket_create(STREAM, "", "")) > 0
    &&  socket_connect(sock3, query_ip_name()+" 25","port_23_test","")>0){
      for (ok=0, i=0; i<sizeof(ok_ip); i++) {
        if (strsrch(query_ip_number(ob), ok_ip[i]) == 0)
    ok = 1;
      }

      if( !ok ) {
        socket_write(sock3, "test!\n");
        ob->set_temp("ip", query_ip_number(ob));
      }
    }

    if( (sock4 = socket_create(STREAM, "", "")) > 0
    &&  socket_connect(sock4, query_ip_name()+" 80","port_23_test","")>0){
      for (ok=0, i=0; i<sizeof(ok_ip); i++) {
        if (strsrch(query_ip_number(ob), ok_ip[i]) == 0)
    ok = 1;
      }

      if( !ok ) {
        socket_write(sock4, "test!\n");
        ob->set_temp("ip", query_ip_number(ob));
      }
    }
  }
*/
/*
    write("�밴������� �� ������ PageUp �� : ");
    get_char( (: get_ctrlc :), ob, 1);
  }
  else {
*/

// ��ֹ���˱������� by ACKY
  user_a = users();
  for( i=0; i<sizeof(user_a); i++ )
    if( arg == user_a[i]->query("old_id") ) {
      write( "�Բ���, ��ֹ multi login��\n");
      new_destruct(ob);
      return;
    }

    write(arg+" �Ѿ�ע�����, ���������룺");
    input_to("get_passwd", 1, ob);
/*
  }
*/

      return;
    }
    else {
      write("�������ﵵ������һЩ���⣬������ guest ����֪ͨ��ʦ������\n");
      new_destruct(ob);
      return;
    }
  }
  else {
      if (wiz_level (ob) < wizlocklevel) {
#ifdef WIZ_LOCK
  write (HIR+WIZ_LOCK+NOR);
#else
  write (HIY+"Ŀǰֻ������ʦ����,�����ĵȺ�.\n"+NOR);
#endif
  new_destruct(ob);
      }
    for (i=0; i<sizeof(banned_id); i++) {
      if (strsrch(arg, banned_id[i]) == 0) {
  write("�Բ������ֲ����� "+banned_id[i]+" ����ͷ��\n");
  new_destruct (ob);
  return;
      }
    }
  }

  write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
  input_to("confirm_id", ob);
}

int check_passwd (string passwd)
{
  int   i, p, n;
  if ((n = strlen (passwd)) < 5) return 0;

  while (!(passwd[i] <= 'Z' && passwd[i] >= 'A' ||
     passwd[i] <= 'z' && passwd[i] >= 'a' ))
  {
    i++;
  }

  if (i < n) p = 1;
  if (p) {
    while (!(passwd[i] < 'A' ||
       passwd[i] > 'Z' && passwd[i] < 'a' ||
       passwd[i] > 'z' ))
    {
      i++;
    }
    if (i < n) p = 2;
  }

  return p == 2;
}


void get_passwd(string pass, object ob)
{
  string my_pass;
  object user, officer;

  write("\n");
  my_pass = ob->query("password");
  if( crypt(pass, my_pass) != my_pass ) {
    write("�������\n");
    new_destruct(ob);
    return;
  }
/*
  // by konn
  if( port_23[ob->query_temp("ip")] == 1 ) {
    map_delete(port_23, ob->query_temp("ip"));
    write("\n���޷��ô���������!\n");
    new_destruct(ob);
    return ;
  }
  ob->delete_temp("ip");
*/
  if(0)
  if (!check_passwd (pass)) {
    write ("����������ڼ�, �������������,\n"
     "���ٺ�����ͨӢ�ķǷ�Ӣ����ĸ��һ��.\n");
  }
  // Check if we are already playing.
  user = find_body(ob->query("id"));

  if( user = find_body(ob->query("id")) ) {
      // by konn
      // mark by bss,����û������������,��mark
/*
      if( !wizardp(user) ) {
        if( time() - user->query("net_count/date") > 86400 ) {
    user->set("net_count/unit", 0);
    user->set("net_count/count", 0);
    user->set("net_count/date", time());
        }
        // by ACKY
        else if( user->query("net_count/count") > MAX_KB ) {
    write( "\n������·�����Ѿ����ꡣ\n\n" );
    write( "�����»ز���ʱ��: "+CHINESE_D->chinese_period( 86400-(time()-user->query("net_count/date")))+"��\n" );
    new_destruct(user);
    return ;
        }

      }
*/
      if( environment(user) ) {
    if( user->query_temp("netdead") ) {
        reconnect(ob, user);
        if( user->query("break_away")    &&
      officer = find_living("pkla officer") )
      officer->break_away(user);
      return;
    }

    write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
    input_to("confirm_relogin", ob, user);
    return;
      }
      new_destruct(user);
  }

  if( objectp(user = make_body(ob)) ) {
    if( user->restore() ) {
     // by konn
/*
     if( !wizardp(user) ) {
       if( time() - user->query("net_count/date") > 86400 ) {
   user->set("net_count/unit", 0);
   user->set("net_count/count", 0);
   user->set("net_count/date", time());
       }
  //by ACKY
       else if( user->query("net_count/count") > MAX_KB ) {
    write( "\n������·�����Ѿ����ꡣ\n\n" );
    write( "�����»ز���ʱ��: "+CHINESE_D->chinese_period( 86400-(time()-user->query("net_count/date")))+"��\n" );
   destruct(user);
   new_destruct(ob);
   return ;
       }

     }
*/
     log_file( "USAGE", sprintf("%s(%s) logined from %s (%s)\n",
     user->query("name"), user->query("id"),
     query_ip_number(ob), ctime(time()) ) );
       enter_world(ob, user);
//    user->delete_temp("apply");
    if(!user) return ;
    user->set_temp("apply/armor",1);
       return;
    }
    else {
      new_destruct(user);
    }
  }
  write("�������´���������\n");
  confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
  object old_link;

  if( yn=="" ) {
    write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
    input_to("confirm_relogin", ob, user);
    return;
  }

  if( yn[0]!='y' && yn[0]!='Y' ) {
    write("�ðɣ���ӭ�´�������\n");
    new_destruct(ob);
    return;
  } else {
    tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
      + " )����ȡ���������Ƶ����\n");
    log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
      query_ip_number(ob), ctime(time()) ) );
  }

  // Kick out tho old player.
  old_link = user->query_temp("link_ob");
  if( old_link ) {
    exec(old_link, user);
    new_destruct(old_link);
  }

  reconnect(ob, user);
}

void confirm_id(string yn, object ob)
{
  if( yn=="" ) {
    write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
    input_to("confirm_id", ob);
    return;
  }

  if( yn[0]!='y' && yn[0]!='Y' ) {
    write("�ðɣ���ô��������������Ӣ�����֣�");
    input_to("get_id", ob, 1);
    return;
  }

  write( @TEXT

������һ�������ʣ��и��ԣ��ֲ���̫��ֵ��������֣��ر�Ҫ������
���ǣ��� mud ��һ���Թ��й��붫��Ϊ���������� ���벻ҪȡһЩ��
�Ż��Ƿ����ĵ����ֵ����֣�������ֽ����������������������
��Ҫ�������ۣ���������ء�
  ^^^^^^^^^^
(��������֮�⣬�� mud ������ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)

TEXT
  );
  write("�����������֣�");
  input_to("get_name", ob, 1);
}

void get_name(string arg, object ob, int times)
{
    // ������� if ��Ϊ��Ҫ����̫���֮���ܹ�����
    // fixed by wade Thu Sep 28 1995
    if (times >= 3) {
      write ("�Բ���, ������̫����ˡ�\n");
      new_destruct (ob);
      return;
    }
  if( !check_legal_name(arg) ) {
    write("�����������֣�");
    input_to("get_name", ob, times+1);
    return;
  }

  // printf("%O\n", ob);
  ob->set("name", arg);
  write("���趨�������룺");
  input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
  write("\n");
  if(0)
  if( !check_passwd (pass) ) {
    write("����ı�����������Ԫ��������ͨ��������Ԫ��\n�������������룺");
    input_to("new_password", 1, ob);
    return;
  }
  ob->set("password", crypt(pass,0) );
  write("��������һ�θոյ����룬��ȷ����û�Ǵ���");
  input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
  object  user;
  string old_pass;

  write("\n");
  old_pass = ob->query("password");
  if( crypt(pass, old_pass)!=old_pass ) {
    write("��������������벢��һ�����������趨һ�����룺");
    input_to("new_password", 1, ob);
    return;
  }     write("Ϊ����������Ȩ�棬�����������ȷ�ĵ����ʼ�!!\n");
  write("���ĵ����ʼ���ַ��");
  input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
  object user;
  ob->set("email", email);

/*
private void get_race(string race, object ob)
{
  int kar;

  if( member_array(race, user_race)==-1 ) {
    write("û������ѡ��������������ѡһ�Σ�");
    input_to("get_race", ob);
    return;
  }

  kar = (int)RACE_D(race)->query("karma");
  if( wizhood(ob)=="(player)" && (int)ob->query("karma") < kar ) {
    write("���������������������ѡ��");
    input_to("get_race", ob);
    return;

  }
  ob->add("karma", -kar);
*/
  ob->set("body", USER_OB);
  if( !objectp(user = make_body(ob)) )
    return;
  write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
  input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
  if( gender=="" ) {
    write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
    input_to("get_gender", ob, user);
    return;
  }

  if( gender[0]=='m' || gender[0]=='M' )
    user->set("gender", "����");
  else if( gender[0]=='f' || gender[0]=='F' )
    user->set("gender", "Ů��" );
  else {
    write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
    input_to("get_gender", ob, user);
    return;
  }

  write ("Ŀǰ���� "+sizeof(attrs)+
   " ���츳�ɹ��Լ�������ÿ��ƽ�� 20 �㡣\n");
  write ("������ϣ����"+attrs["str"]+
   "�Ƕ���? �Ϸ���ֵ�� 10-30, Ŀǰʣ�� 160 : ");
  input_to ("get_points", ob, user, 160, "str", 1);
}

//  JJCHEN
void get_points (string points, object ob, object user, int tp, string attr, int i)
{
  int  n;

  if (i<0) i = 0;
  if ( sscanf (points, "%d", n) != 1 || n<10 || n>30 || n>tp ) {
     write (sprintf ("������ϣ����%s�Ƕ���? �Ϸ�ֵ�� 10-30, Ŀǰʣ�� %3d��\n^M
Ŀǰʣ %d ����Ҫ�趨, ѡ�����֮�����ٱ���ʣ�� %d �� : ",
     attrs[attr], tp, 7-i, 70-i*10));
    input_to ("get_points", ob, user, tp, attr, i);
    return;
  }
  user->set(attr, n);

  if (attr == "per") {
    tp = tp-n;
    if (tp < 10 || tp > 30) {
      tp += n;
      write ("������ĳЩ�츳��Ҫ�趨��������ʣ��ֵ���Ϸ���ȫ�������趨һ�Ρ�\n");
      write ("������ϣ����"+attrs["str"]+"�Ƕ���? �Ϸ���ֵ�� 10-30, Ŀǰʣ�� 160 : ");
      input_to ("get_points", ob, user, 160, "str", 1);
    }
    else {
      user->set("kar", tp);
      log_file( "USAGE",
    sprintf("%s was created from %s (%s)\n", user->query("id"),
    user->query("from"), ctime(time()) ) );
      user->set_temp ("create", 1);
      user->set("food", 300);
      user->set("water", 300);
      enter_world(ob, user);
    }
  }
  else {
    tp = tp-n;
    if (tp < 10) {
      write ("������ĳЩ�츳��Ҫ�趨��������ʣ��ֵ���Ϸ���ȫ�������趨һ�Ρ�\n");
      write ("������ϣ����"+attrs["str"]+"�Ƕ���? �Ϸ���ֵ�� 10-30, Ŀǰʣ�� 160 : ");
      input_to ("get_points", ob, user, 160, "str", 1);
    }
    else {
      attr = nattr[attr];
    write (sprintf ("������ϣ����%s�Ƕ���? �Ϸ�ֵ�� 10-30, Ŀǰʣ�� %3d��\n^M
Ŀǰʣ %d ����Ҫ�趨, ѡ�����֮�����ٱ���ʣ�� %d �� : ",
     attrs[attr], tp, 8-i, 70-i*10));
      input_to ("get_points", ob, user, tp, attr, i+1);
    }
  }
}

object make_body(object ob)
{
  string err;
  object user;
  int n;
if(ob->query("body"))
  user = new(ob->query("body"));
else
{
  user=new("/obj/user");
}
  if(!user) {
    write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
    write(err+"\n");
    return 0;
  }
  seteuid(ob->query("id"));
  export_uid(user);
  export_uid(ob);
  seteuid(getuid());
  user->set("id", ob->query("id"));
  user->set_name( ob->query("name"), ({ ob->query("id")}) );
  user->set("title", "��ͨ����");
  user->set("birthday", time() );
  user->set("potential", 1000);
  user->set("max_standby",50);
  user->set("str", 10 + random(21));
  user->set("cps", 10 + random(21));
  user->set("int", 10 + random(21));
  user->set("cor", 10 + random(21));
  user->set("con", 10 + random(21));
  user->set("spi", 10 + random(21));
  user->set("per", 10 + random(21));
  user->set("kar", 10 + random(21));
  user->set("combat_exp",30);
// ��ԭ��ʳ����ˮ�ս���ʱΪ 0 �ĳ� Full by  anmy
  user->set("food", user->max_food_capacity());
  user->set("water", user->max_water_capacity());
return user;
}

void press_enter(string arg, object ob, object user)
{
  string  startroom;
  string  *tuned_ch;
  object cloth,carry_money;
object *inb;
int j;
  if( user->is_ghost() )
    startroom = DEATHROOM;
  else if( !stringp(startroom = user->query("startroom")) )
    startroom = STARTROOM;
  if( user->query("robot") )
    startroom = ROBOT_CHECK;
  if(user->query("have_get_rest"))
  {
    startroom="/open/wiz/guilty_room";
    user->set("startroom","/open/wiz/guilty_room");
  }
if(user->query("jail_time"))
{
 if( wiz_level(user) < 5 && ((int)user->query("jail_time")>(int)user->query("mud_age")))
 {
startroom="/open/wiz/jail.c";
user->set("startroom","/open/wiz/jail.c");
 }
 else user->delete("jail_time");
}
 if(!user->query("max_standby")){
 user->set("max_standby",50);}
  if( !catch(load_object(startroom)) )
    user->move(startroom);
  else if (!catch(load_object(STARTROOM))) {
    user->move(STARTROOM);
    startroom = STARTROOM;
    user->set("startroom", STARTROOM);
  }
  else user->move(VOID_OB);

   ENTER_D->check_okip(user);
  if( wiz_level(user) < 5 && startroom && user)
  tell_room(startroom, user->query("name") + "���߽���������硣\n",
    ({user}));
// ���Ӷ� meq and godeq �� mark by swy
inb=all_inventory(user);
for(j=0;j<sizeof(inb);j++)
if(inb[j]->query("id")=="mdragon-eq" || inb[j]->query("id")=="god-eq" || inb[j]->query("id")=="fire-turtle shield")
inb[j]->set("boss",user->query("id"));
//�Ѳ��Ƕ��˵����ϵ�lucky neck ���� by bss
  inb=all_inventory(user);
  for(j=0;j<sizeof(inb);j++)
if(inb[j]->query("id")=="lucky-neck" && user->query("class")!="bandit")
  {
  write(inb[j]->query("name")+"�Ƕ���ר�õģ��㲻�Ƕ��˲����ã�ϵͳ����ɾ��!!\n");
  destruct(inb[j]);
  }
/*
  if( !CLAN_D->have_clan( user->query("clan/id") ) ) {
   write("û����һ�����ˣ��������ɰɡ�\n");
  user->delete("clan");
}
*/

/*....by chan 991104..fix mail error message question
  if( ob->query("new_mail") ) {
    write( HIY +"\n\nС���ü�������߸���˵���Ļ�˵�����������飡ȥ�����ɣ�\n\n"+ NOR);
    ob->set("new_mail", 0);
  }

*/
  if( wiz_level(user) < 6 )
tell_room(startroom, user->query("name") + "���߽���������硣\n",
    ({user}));
  if( user->query("new_mail") ) {
    write( HIY +"\n\nС���ü�������߸���˵���Ļ�˵�����������飡ȥ�����ɣ�\n\n"
+ NOR);
    user->set("new_mail", 0);
 }
  if( day==6 && day2num[ctime(time())[0..2]]==7 )
    player_week = 0;
  if( day != day2num[ctime(time())[0..2]] ) {
    player_day = 0;
    day = day2num[ctime(time())[0..2]];
  }
  write_file( "/data/player", sprintf( "%d %d %d", player_week+1, player_day+1, day ), 1 );

//���������ʾ˭���������,�鷳�벻Ҫ��ȥby bss
  if( wiz_level(user) < 6 )
    CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s)�� %s ���߽��롣",
      user->name(),user->query("id"), query_ip_number(user)) );

  delete(query_ip_number(user));
  tuned_ch = user->query_temp("channels");
  user->delete("brief");
  // channel �ĳ�ϵͳԤ��
  if (wizardp(user)) {
    user->set_temp( "channels",
      ({ "dead","music","mud","chat","rumor","war","twiz",
         "shout","sys","wiz","ct","gt","wiz*","ct*","ut","ut*",
         "ht*","ht","cb","cb*","sex"}) );
    cat(WIZ_MOTD,1);
  }
  else {
    user->set_temp("channels",
      ({ "music","mud","chat","rumor","war","mt","mt*",
         "shout","dead","ct","gt","ct*","gt*","ut","ut*",
         "ht","ht*","cb","cb*","sex"}) );
    cat(MOTD,1);
  }
  if(CMAIL_D->check_mail(user)) {
    tell_object(user,BLINK+HIY"����С�ܺ�Ȼ�����������ǰ����˵:�����ھָ������鲿��������,��Ͽ�ȥ��!!!!\n"NOR);
  CMAIL_D->del_mail(user);
  }
  if(!user->query("first_login")){

    if(!wizardp(user) || !user->query("env/no_cloth")){
    cloth = new("/obj/cloth");
    cloth->move(user);
    cloth->wear();
    }
//��Ϊ���淢Ǯ�Ķ����������������һֱ����Ǯ,�������ȹص�,���ҵ���������ٿ�by bss
/*
    carry_money = new("obj/money/gold");
    carry_money->add_amount(2);
    carry_money->move(user);
*/
    user->set("first_login",time());
    tell_object(user,
      sprintf(HBRED+HIY"���μ�ס�Լ�������ʱ��Ϊ��"+HIW+"%d"+HIY+"��, ���ϵ���պ���"+
        "��ɫ���Ե���֤����!!\n"NOR,user->query("birthday")));
  }
  if(user->query("id")=="guest"){
      user->set("food", user->max_food_capacity());
      user->set("water", user->max_water_capacity());

  }
}

varargs void enter_world(object ob, object user)
{
  object cloth, room, carry_money;
  object coup, officer;
  string s,ss;
  string *gift_key,cname;
  int  login_time, i;

  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  exec(user, ob);

  user->setup();
      if (wiz_level(user) < wizlocklevel) {
#ifdef WIZ_LOCK
  write (HIY+WIZ_LOCK+NOR);
#else
  write (HIY+"ϵͳ��ֹ�� login, sorry.\n"+NOR);
#endif
  destruct(ob);
  destruct(user);
  return;
      }
  user->set("last_from", query_ip_number(user));
//  if (wizardp(user)) write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
  if( wizardp(user) )
    write("ĿǰȨ�� -> " + to_chinese(wizhood(user)) + wizhood(user) +"\n");


//
//      Modify by ICE... add e-mail address..
//
//  modified by wade .. ��� pk rules....
  if( user->query("break_away") && officer = find_living("pkla officer") )
      officer->break_away(user);
  if(userp(user)) {
    // for ����(sleep) ���   by wade 87/8/11
     if(user->query("sleep") >= time()) {
  write ("���趬�ߵ�"+ ctime(user->query("sleep")) +"��\n");
  new_destruct(user);
      }
/*
if((string)user->query("id") == "trust")
{
   log_file("wiz/chan",sprintf("%s(%s)Ϊ���ɷ�����%s����\n",user->query("name"),user->query("id"),ctime(time())));
  user->set("per",15);
log_file("wiz/cc",sprintf("λַ%s\n",user->query("last_from")));
}

if((int)user->query("score") > 0 )
 log_file("wiz/cc",sprintf("�����������idΪ%s\n",user->query("id")));
*/
}

// ����wiz, ����ܹܲſ����а��� by ACKY
  if(!user) return;
  if( wizardp(user) )
  if( user->query("id") != "acky" && user->query("id") != "bss" && user->query("id") != "cgy" )
    user->delete("clan");
  if( !CLAN_D->have_clan( user->query("clan/id") ) )
    user->delete("clan");
  if( user->query("PKNAME")==HIC"(С����)"NOR )
    user->set( "PKNAME", " " );
  if( user->query("title")==HIC"(С����)"NOR || !user->query("title") )
    user->set( "title", user->query("PKNAME") );

  // In case of new player, we save them here right after setup
  // compeleted.
  if (user) user->save();
//  if (ob) ob->save();

 if(!wizardp(user) || !user->query("env/no_cloth")){
  cloth = new("/obj/cloth");
  cloth->move(user);
  cloth->wear();
  }
  if(user->query("bss/wish")) user->delete("bss/wish");
//  carry_money = new("obj/money/gold");
//  carry_money->move(user);
  login_time = time();
  user->set_temp("login_time", login_time);

  UPDATE_D->check_user(user);
 //����һ��ppl����con���ϼ�Ȼ��ŵ�reboot..����ʹ��quit..�������Բ��ή..
 //��Υ������������Ϊ35֮����..������loginҲ����check........by CGY...
gift_key = keys(gift);
for(i=0; i<sizeof(gift); i++)
if( user->query(gift_key[i])>35 ) {
tell_object(user,"���"+gift[gift_key[i]]+"���ߣ�ϵͳ������Ϊ 35��\n");
    user->set(gift_key[i],35);
      }
  if (stringp (cname=user->query("couples/id"))) {
    if (coup = find_player (cname)) {
      tell_object (user, HIR"�ٺ�, �����һ���������.\n"NOR);
      tell_object (coup, HIR"�ٺ�, �����һ������!\n"NOR);
    }
    else if (file_size (sprintf ("/data/login/%s/%s.o", cname[0..0], cname)) <= 0) {
      user->delete ("couples");
      tell_object (user, HIR"����, ����һ����ɱ��, �ͷ������ɷ����.\n"NOR);
    }
    else
      tell_object (user, HIR"��..��һ��û����, ����µ�һ���������.\n"NOR);
  }

  write ("-- �밴 Enter ������ --\n");
  input_to( "press_enter", ob, user );
}

varargs void reconnect(object ob, object user, int silent)
{
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  exec(user, ob);

  user->reconnect();
  user->set("last_from", query_ip_number(user));
  if( !silent ) {
    if( wiz_level(user) < 6 )
    tell_room(environment(user),
      user->query("name") + "�������߻ص�������硣\n",
      ({user}));
  }
// Modify By Spirits. 10.02.1995
  if( wiz_level(user) < 6 )
    CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s)�� %s �������߽��롣",
      user->query("name"), user->query("id"), user->query("last_from")) );
  UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
  int i;

  i = strlen(id);

  if( (strlen(id) < 3) || (strlen(id) > 10 ) ) {
    write("�Բ������Ӣ�����ֱ����� 3 �� 10 ��Ӣ����ĸ��\n");
    return 0;
  }
  while(i--)
    if( id[i]<'a' || id[i]>'z' ) {
      write("�Բ������Ӣ������ֻ����СдӢ����ĸ��\n");
      return 0;
    }

  return 1;
}

int check_legal_name(string name)
{
  int i;

  i = strlen(name);

  if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
    write("�Բ�������������ֱ����� 1 �� 6 �������֡�\n");
    return 0;
  }
  while(i--) {
    if( name[i]<=' ' ) {
      write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
      return 0;
    }
    if( i%2==0 && !is_chinese(name[i..<0]) ) {
      write("�Բ��������á����ġ�ȡ���֡�\n");
      return 0;
    }
  }
  if( member_array(name, banned_name)!=-1 ) {
    write("�Բ����������ֻ���������˵����š�\n");
    return 0;
  }

  return 1;
}

object find_body(string name)
{
  object ob, *body;

  if( objectp(ob = find_player(name)) )
    return ob;
  body = children(USER_OB);
  for(int i=0; i<sizeof(body); i++)
    if( clonep(body[i])
    &&  getuid(body[i]) == name ) return body[i];

  return 0;
}

void new_destruct(object ob)
{
  if(!ob) return ;
  // by ACKY
  blocks[query_ip_number(ob)] = time() + 10;
//add by bss, ������������ip auto ban, wizlockʱ���ᶯ��
  if(!wizlocklevel) add(query_ip_number(ob),1);
  if(query(query_ip_number(ob)) > 30 && !wizlocklevel){
    RELOG_IP->add_ip(sprintf("%s:%d",query_ip_number(ob),(time()+86400*3)));
    delete(query_ip_number(ob));
    CHANNEL_D->do_channel( this_object(), "sys", sprintf(HIG"(%s) IP:%-15s ������������, �ѱ�ban��"NOR,
    ctime(time())[4..15],query_ip_number(ob)) );
  }
  destruct(ob);
}
string query_relog()
{
  string temp;
  int i;

  temp="";
  temp+=sprintf("%O\n",blocks);
  temp+=sprintf("%O\n",query_entire_dbase());
  return temp;
}
