#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
string do_mdragon();
string do_mblade();
void create()
{
set_name("ÄªÎÞ³î",({"master mou","mou","master"}));
set("long","ÉñÃØÀÏÈËµÄ°®¶ù£¬¶þÊ®ÓàÄêÀ´ÈÌÈèÍµÉú£¬ÎªµÄÊÇÕÒÑ°¶À¹Â³î£¬±¨Æä¸¸Õ®£¬Æä¿ñÁúµ¶·¨ÒÔ¿ì
´ïµ½Æä¸¸µÄË®×¼£¬ÓÖÒò¼øÓÚµ±³õ¸¸Ç×Ëù·¸ÏÂµÄ´íÎó£¬¸ÄÁ¼¡¾¿ñÁúÅ­Õ¶¡¿ÑÐ·¢³ö¡¾Ä§Áú¾÷¡¿
ËäÍþÁ¦²»¼°¸¸Ç×£¬µ«È·ÓÐÆäÒþ²ØµÄºó¾¢£¬ÇÒÁ¢ÊÄÓë¶À¹Â³îºó´ú´«ÈËÊÆ²»Á½Á¢¡£\n");
set("gender","ÄÐÐÔ");
set("attitude","heroism");
set("age",35);
set("class","blademan");
set("nickname",HIR"¸´³ðÄ§µ¶"NOR);
set("title","Ä§µ¶ÃÅµÚ¶þ´úÕÆÃÅ");
create_family("Ä§µ¶ÃÅ",2,"ÕÆÃÅ");
set("score",100000);
set("force",4000);
set("max_force",4000);
set("env/Ä§ÐÔÁùÕ¶","YES");
set("max_kee",30000);
set("force_factor",25);
set("mpower",1);
set("cor", 35);
set("str", 35);
set("per", 20);
set("int", 25);
set("functions/mdragon-dest/level",100);
set("cps", 35);
set("con", 35);
set("spi", 25);
set("kar", 35);
set("combat_exp", 1000000);
set("bellicosity", 3000);
set_skill("riding",80);
set_skill("force", 90);
set_skill("parry", 90);
set_skill("move", 60);
set_skill("dodge", 60);
set_skill("cure", 50);
set_skill("dragon-blade",105);
set_skill("powerforce", 90);
set_skill("blade", 100);
set_skill("literate", 40);
set_skill("unarmed", 20);
set_skill("spells", 20);
set_skill("magic", 20);
map_skill("parry","dragon-blade");
map_skill("blade","dragon-blade");
map_skill("force","powerforce");
set("chat_chance",40);
set("chat_msg",({
HIW"°¦£¡¶¼ÕÒ²»µ½ÎÒ¸¸Ç×¡«Ä§µ¶Äª²â\n"NOR,
HIW"ÎÒµÄ¿ñÁúµ¶·¨ÒÑ´ïÉÏÏÞ£¬µ«ºÍ¸¸Ç×±ÈÆðÀ´ÓÖ²îÁËÒ»½Ø\n"NOR,
HIY"ÌýËµÎÒ¸¸Ç×ÓÐÒ»°ÑÕò½ÌÖ®±¦£¬²»¹ýÏêÇéÒ²Ö»ÓÐÎÒ¸¸Ç×Öª\n"NOR,
}));
set("inquiry",([
"Ä§Áú¾÷"  : (: do_mdragon :),
"Ä§µ¶Äª²â":"ÌýËµÎÒ¸¸Ç×±»¹ØÔÚÑ©²ÔºóÉ½Àï£¬µ«ÎÒÒ»Ö±ÕÒ²»µ½£¬Ãþ²»×ÅÍ·Ð÷¡£",
"¿ñÁúÅ­Õ¶":"ÄÇÊÇÎÒ¸¸Ç×ÑÐ¾¿³öÀ´µÄ£¬±ÈÎÒµÄÄ§Áú¾÷Ç¿ÉÏÊý±¶¡£",
"¿ñÁúµ¶·¨":"ÄÇÊÇÎÒ¸¸Ç×µ±ÄêËù×ÔºÀµÄµ¶·¨£¬ÌýËµ»¹ÓÐÊ§´«°ÂÒåºÍ¿ñÁúÅ­Õ¶¼°ÈýÕ¶¹éÔª¡£",
"Ê§´«°ÂÒå":"ÎÒ²»Ì«Çå´¦£¬´«µ½ÎÒÊ±ÒÔÃ»ÄÇÕÐÁË£¬ÄÇÕÐÖ»ÓÐÎÒ¸¸Ç×»á¡£",
"ÈýÕ¶¹éÔª": (: do_mblade :),
]));
set("chat_chance_combat",100);
set("chat_msg_combat",({
(: perform_action, "blade.mdragon-dest" :),
}));
set_temp("apply/armor",65);
set_temp("apply/damage",65);
setup();
carry_object("/daemon/class/blademan/obj/ublade.c")->wield();
carry_object("/daemon/class/blademan/obj/shield.c")->wear();
carry_object("/daemon/class/blademan/obj/six-neck.c");
add_money("gold",10);
}

// by acky ÕÒ³ö×÷±×Õß
void greeting(object ob)
{
    if(!ob) return ;
	if( ob->query("get-evil-mblade")==1 ) {
        if( ob->query("family/family_name")!="Ä§µ¶ÃÅ" && ob->query("family/family_name")!="Ä§µ¶Äª²â" && !wizardp(ob)) {
			command( "chat "+ob->query("name")+"("+ob->query("id")+")ÄãÕâ¸ö×÷±×µÄÎÞ³ÜÖ®Í½, ¸øÎÒÈ¥ËÀ°É!" );
			kill_ob(ob);
			log_file( "BUG/Ñýµ¶", sprintf("%s %s(%s)·ÇÄ§µ¶ÃÅÈË, È´³ÖÓÐÑýµ¶\n"
				,ctime(time())[0..15], ob->query("name"), ob->query("id") ) );
			return;
		}
		if( !present( "evil-mblade", ob ) ) {
			new("/data/autoload/blademan/evil-mblade.c")->move(ob);
			command( "say Äã¾¹È»°ÑÎÒÃÅµÄÕò½ÌÖ®±¦¸øÅª¶ªÁË!" );
			command( "waggle "+ob->query("id") );
			command( "say ÒªÊÇÏÂ»ØÔÙÅª¶ª, ¿É¾Í²»¹ÜÄã!" );
			message_vision( HIY"ÄªÎÞ³î´ÓÉíÅÔÄÃ³öÑýµ¶½»µ½$NÊÖÖÐ!\n"NOR, ob );
			command( "say ÇëºÃºÃ±£¹ÜºÃ°É!" );
		}
	}
}

void attempt_apprentice(object obj)
{
      command("l "+obj->query("id"));
    if(obj->query("title") == HIR"É±ÊÖÈ«Á¦×·É±µÄÈËÍ·"NOR)
	{
		command(" say ËÀÐ¡º¢....ÓÖÏëÀ´×÷±×£¡£¡");

	return ;
}
if(obj->query("kar",1)<25||obj->query("have_officer",1)==1||obj->query("family/family_name")=="½ðµ¶ÃÅ")
      {
          command("sigh "+obj->query("id"));
          command("say ÄªÄ³ÓëÄãÎÞÔµ£¬Äã×ß°É¡£\n");
          command("shake");
          return;
      }
command(":)");
command("say ºÃÐ¡×Ó£¬¹ûÈ»ÓÐÎÞ±ÈµÄµ¨Á¿¡£");
command("say ºÃ£¬ÎÒÊÕ"+this_player()->name()+"ÎªÎÒÃÅÍ½¡£");
obj->delete("family");
command("recruit "+obj->query("id"));
if(this_player()->query("m_blade")==1) {
this_player()->set("title","[1;31mÄ§µ¶[1;37m¡®ÈýÕ¶¹éÔª¡¯[1;35m´«ÈË[0m");
}
message("system",HIW"ÄªÎÞ³î×ÝÉù³¤Ð¦:
\n¹þ¹þ¹þ¹þ¡«¡«Ä§µ¶¸´³ð½«ÖÁ¡£"NOR,users());
message("system",HIR"\n\n½ñºó"+this_player()->name()+"½«»áÌæÎÒÑªÏ´¶À¹ÂÀÏÔô¡£\n"NOR,users());
this_player()->set("no_recruit", 1);
 return ;
}
void init()
{
object ob;
::init();
if(interactive(ob =this_player()) && !is_fighting() ) {
remove_call_out("greeting");
if(ob)
call_out("greeting",1,ob);
}
add_action("do_verify","verify");
}
int do_verify(string arg)
{
object me,ob;
me=this_player();
ob=new("/data/autoload/blademan/mblade");
if(arg!="blade")
{
  write("ÄãÒªÄÃÊ²Ã´°¡£¿\n");
  return 1;
  }
if((me->query("family/family_name")!="Ä§µ¶ÃÅ")&&me->query("family/family_name")!="Ä§µ¶Äª²â")
  {
    write("Ö»ÓÐÄ§µ¶ÃÅÍ½²Å»áÓÐà¸¡£\n");
    return 1;
  }
if(arg=="blade")
{
if(present("mblade",me))
{
      write("ÄãÓÐµ¶ÁË»¹Òª¡£\n");
      return 1;
}
      write("°¡£¿Äã°Ñµ¶×Ó¶ªÀ²£¬ÎÒÔÙ¸øÄãºÃÁË¡£\n");
      ob->move(me);
      return 1;
} 
}
string do_mdragon()
{
object who;
who=this_player();
if(who->query("family/family_name")!="Ä§µ¶ÃÅ"&&who->query("family/family_name")!="Ä§µ¶Äª²â")
{
command("say ÄãÔõ»áÖªµ½Ä§Áú¾÷£¬ÄÑµÀÊÇ¶À¹ÂÀÏÔôÅÉÄãÀ´µÄ¡£");
command("say ¼ÈÈ»Èç´Ë£¬ÎÒ¾Í²»ÄÜÈÃÄã»î×Å»ØÈ¥£¬ºÙºÙºÙ¡£");
command("kill "+who->query("id"));
return "É±ËÀÄã£¬¿É¶ñµÄ¼äµú¡£";
}
command("say ÕâÊÇÎªÊ¦±ÏÉúËùÑÐ¾¿³öÀ´µÄ£¬Õâ¾Í´«ÊÚ¸øÄãÁË¡£");
command("say ÓÃ·¨(perform blade.mdragon-dest)£¬µ«Òª¿ñÁúµ¶·¨¡®105¡¯²ÅÄÜÓÃ¡£");
return "Ï£ÍûÄãÄÜºÃºÃÓÃÖ®¡£";
}

string do_mblade()
{
  object me;
  me=this_player();
  if( me->query_skill("dragon-blade",1) < 90 ) {
  command("say Äã¿ñÁúµ¶·¨ÐèÒªÔÙ¼ÓÇ¿Ð©£¬²»ÒªºúË¼ÂÒÏë");
  return "È¥¼ÓÇ¿ÄãµÄµ¶·¨°É"; }
  if( me->query("combat_exp") < 3000000 ) {
  command("say ÄãÊµÕ½¾­Ñé²»×ã¡£");
  return "È¥¼ÓÇ¿ÄãµÄÊµÕ½¾­Ñé°É"; }
  if( me->query("snow-head",1) < 700 ) {
  command("say ÄãÉ±µÄÑ©²ÔµÜ×Ó»¹²»¹»£¬µÈ¹»ÁËÔÙËµ°É");
  return "È¥¶àÉ±µãÑ©²ÔµÜ×Ó°É"; }
command("say ÄÇÊÇÄ§µ¶ÖÁÒõÖÁ¶¾µÄÕÐÊ½£¬ÎÒ¸¸Ç×´«ÎÒÐÄ·¨Ö®ºó£¬Ò²²ÅÏ°µÃÒ»Ê½");
command("say ³ý·Ç£¬ÄãÄÜÄÃ¶À¹ÂáÓµÄÈËÍ·À´£¬ÄÇÑùÄã²ÅÓÐ×Ê¸ñÄÜÏ°µÃ´ËÐÄ·¨");
command("say ¶À¹ÂáÓÊÇÄ§µ¶µÄÊÀ³ð£¬±»¹ØÔÚÄ§µ¶ÃÅÄÚ£¬µ«ÊÇÒ»Ö±ÓÐÈËÏëÈ¥½â¾ÈËû");
command("say ÇÒ¶À¹ÂáÓµÄµÜ×ÓÕ¼¾ÝÄ§ÁúËþ¶àÄê£¬µÈ´ý¶À¹ÂáÓµÄ¹éÀ´£¬ÏëÒ»¾ÙÏûÃðÎÒÃÅ");
return "ËùÒÔ£¬Ö»ÒªÄãÄÜÏûÃð¶À¹ÂáÓÎÒ¾Í´«ÄãÐÄ·¨";
}

int accept_object(object who, object ob)
{
object mid;
if(ob->query("id") == "sa-head")
{
destruct(ob);
say("ÄªÎÞ³î¿´ÁË¿´¶À¹ÂáÓµÄÍ·ËµµÀ : ÕâÊÇ¡®ÎäÌìÖÁÊ¥¡¯¶À¹ÂáÓµÄÍ·¡£\n");
if(who->query("family/family_name")=="Ä§µ¶ÃÅ"||who->query("family/family_name")=="Ä§µ¶Äª²â")
{
     if(!who->query("m_blade",1))
     {
if(who->query("combat_exp") < 3000000 ) {
say("ÄãÊµÕ½¾­Ñé²»×ã£¬ÔÙÈ¥¶àÐÞÁ·°É£¡\n");
return 1;
}
if(!who->query_temp("ko_sa")) {
say("ËûÓÖ²»ÊÇÄãÉ±µÄ£¬±ðÏëÃÉÆ­¹ý¹Ø£¡\n");
return 1;
}
if(who->query("snow-head",1)<700)
{
say("Äã»¹²»¹»Ð°¶ñ£¬ÔÙÈ¥¶àÉ±Ò»Ð©ÈË°É£¡\n");
}
else
{
        say("Ã»Ïëµ½Äã¾¹ÄÜÉ±µÄÁËËû£¬ºÃ°É£¬ËãÄã¶Ô±¾ÅÉÓÐËù¹±Ï×¡£\n"
            "ÎÒ½«Ä§µ¶µÄ¡®ÈýÕ¶¹éÔª¡¯ÐÄ·¨´«ÊÚ¸øÄã°É¡£\n"
            "ÖÁÓÚÈçºÎÔËÓÃ£¬×Ô¼ºÈ¥Ìå»á°É£¬¹þ¹þ¹þ£¡\n");
        message("system",HIC"ÄªÎÞ³î¹îÒìÐ¦µÀ£º\n"HIW"
                Ä§µ¶¡®ÈýÕ¶¹éÔª¡¯"HIC"ÖÕÓÚºó¼ÌÓÐÈËÁË\n
                ¿´À´²ùÆ½Ñ©²ÔÖ®ÈÕ²»Ô¶Ñ½£¡\n"HIR"
        ¹þ£¡¹þ£¡¹þ£¡"+this_player()->name()+"Ä§µ¶¸´³ðÈ«¿¿ÄãÁË£¡\n"NOR,users());
        who->set("m_blade",1);
        who->set("title","[1;31mÄ§µ¶[1;37m¡®ÈýÕ¶¹éÔª¡¯[1;35m´«ÈË[0m");
log_file("mblade/m_blade",sprintf("%s½âµ½Ä§µ¶ºóÈý\n",
who->short()));
}}
/*
       else if(who->query("t_standby")<who->query("max_standby"))
       {
        say("ÄãÐÄ·¨ÒÑ¾­»áÁË£¬µ«Ä§µ¶ÈËÒªÓÐÐ°¶ñÖ®ÆøÎª¸¨×¡£¡£¡\n"
            "ÄÇÎÒ¾ÍËÍÄãÒ»¸ö±£Ãü½ðÉí°É£¬Î£ÏÕÊ±ÄÜ±£ÄãÐ°¶ñÖ®Æø£¡£¡\n");
log_file("mblade/standby",sprintf("%s»»ÁËÒ»¸öÌæÉí\n",
who->short()));
who->add("standby",1);
who->add("t_standby",1);
       }
	   else message_vision( HIW"\nÐ¡Ñ©ÇòËµµÀ£ºÄãÔø¾­ÓµÓÐµÄÌæÉí×ÜÊýÒÑ´ïÉÏÏÞ£¬ÎÞ·¨ÔÙÔö¼Ó£¬ÎÒÎÞ·¨°ïÖúÄã¡£\n\n"NOR, who );
*/
     }
else
{
      if(!who->query("get_atman",1))
       {
        say("Ã»Ïëµ½ÎÒÄ§µ¶ÃÅµÄËÞµÐ£¬¾¹»á±»ÄãËùÉ±£¬¿´À´ÌìÒâÄÑÎ¥¡£\n"
            "ºÃ£¡¼ÈÈ»ÈËÊÇÄãÉ±£¬ÎÒ¾Í´«ÎÒ²¿·ÝÁéÁ¦ºÍ·¨Á¦¸øÄã°É¡£\n");
message_vision(HIC"ÄªÎÞ³î½«ÊÖÖ¸Ïò$NÃ¼ÐÄ£¬Ë²Ê±ÁéÆø¹á¶¥£¬$NÉíÉÏÉ¢·¢³öÒõÁéÖ®Æø¡£\n"NOR,who);
        who->add("max_atman",200);
        who->add("max_mana",200);
        who->add("atman",200);
        who->add("mana",200);
        who->set("get_atman",1);
       }
/*.
      else if(who->query("t_standby")<who->query("max_standby"))
       {
        say("ºÙºÙ£¡ÄãÒÑµÃÎÒÁéÁ¦Óë·¨Á¦£¬µ«ÈËÐÄÏÕ¶ñÄÇÎÒÔÙËÍÄã\n"
            "Ò»¸ö±£Ãü½ðÉíºÃÁË£¡Ð¡ÐÄÐ°¶ñÖ®ÈËÑ½£¡¹þ¹þ¹þ£¡\n");
log_file("mblade/standby",sprintf("%s»»ÁËÒ»¸öÌæÉí\n",
who->short()));
who->add("standby",1);
who->add("t_standby",1);
       }
	   else message_vision( HIW"\nÐ¡Ñ©ÇòËµµÀ£ºÄãÔø¾­ÓµÓÐµÄÌæÉí×ÜÊýÒÑ´ïÉÏÏÞ£¬ÎÞ·¨ÔÙÔö¼Ó£¬ÎÒÎÞ·¨°ïÖúÄã¡£\n\n"NOR, who );
*/
     }
  }
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
   if( random(100) > 70)
 {
    enemy=mob->query_enemy();
	if( i = sizeof(enemy) ) {
   target=offensive_target(mob);
    if(target)
    if( env == environment(target) )
    {
message_vision(HIY"
ÄªÎÞ³îÊ©Õ¹³öÄ§µ¶¡®ÈýÕ¶¹éÔª¡«ÓãÁúÊÈÔª¡¯\n"+
"£®£®£®¡®ÓãÁú¶¾ð²¡«¡«»Íá°´ÔÃð¡¯£®£®£®\n"+
"$NÉÁ±Ü²»¼°£¬±»´òÖÐÒªº¦£¬ÑªÁ÷ÂúµØ\n"NOR,target);
    target->receive_damage("kee",600,mob);
      COMBAT_D->report_status(target,1);
    }
	}
 }
   ::heart_beat();
}
int accept_kill(object who)
{
who=this_player();
command("wear all");
command("kill "+who->query("id"));
command("perform blade.mdragon-dest");
return 1;
}
int accept_fight(object who)
{
who=this_player();
command("wear all");
command("kill "+who->query("id"));
command("perform blade.mdragon-dest");
return 1;
}

void die()
{
	object winner = query_temp("last_damage_from");

	int j;
	if(!winner)
	{
	::die();
	return ;
	}

   if (winner && userp(winner))  {
tell_object(users(),HIR"\n\nÄªÎÞ³îÑöÌìÅ­ºð£º\n\n\t¿ÉºÞµÄ"+winner->name()+HIR"¾¹×è°­ÎÒ¸´³ð´óÒµ£¡
\n\tÀÏ×Ó»áÔÙ»ØÀ´±¨³ðµÄ£¡µÈ×Å°É£¡\n\n"NOR);
   }

	if( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj11/orange-crystal")->move(environment(winner));
	  message_vision(HIM"\n´ÓÄªÎÞ³îµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/orange_crystal",sprintf("%s(%s) ÈÃÄªÎÞ³îµôÏÂÁË³ÈÉ«¹â¾§ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/orange-crystal")->move(environment(winner));
	  message_vision(HIM"\n´ÓÄªÎÞ³îµÄÉíÉÏµôÏÂÁËÒ»¼þÆæ¹ÖµÄ¶«Î÷!!\n"NOR,winner);
          write_file("/log/sky/orange_crystal",sprintf("%s(%s) ÈÃÄªÎÞ³îµôÏÂÁË³ÈÉ«¹â¾§ÓÚ %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}

        :: die();
}
