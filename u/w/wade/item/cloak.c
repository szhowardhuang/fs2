
// Ğ´µÄÓĞµãÍ·»èÄÔÕÍ..ÓĞ bug µÄ»°¼ÇµÄ¸æËßÎÒà¸:P..»¹ÓĞĞÂµÄµã×ÓÒ²±ğÍüÁË:P



#include <mudlib.h>

#include <daemons.h>

#include <money.h>

#include <ansi.h>

#include <language.h>

#include <man.h>



inherit ARMOR;

inherit DAEMON;

string inputstr,verb;



void create()

{

  set("name"," ´óÄ§µÀÊ¿Åû·ç");

  set("id",({"Magic cloak","cloak","´óÄ§µÀÊ¿Åû·ç"}));

  set("short",
    this_player()->query("chi_name")+ "µÄ´óÄ§µÀÊ¿Åû·ç(Magic cloak)");

set("long",@LONG

    ÕâÊÇÒ»¼şÊÜ¹ı¹Å·¨ÀÏÍõ×çÖäµÄÅû·ç£¬ÌıËµÖ»ÒªÈÎºÎÈËÒ»´©ÉÏËû¾Í»áÓĞ..bug³öÏÖ

    ¼üÈë<help cloak>ÒÔ»ñµÃ¸ü¶àµÄ×ÊÑ¶¡£

LONG

);

  set("unit","¼ş");

  set("mass",1);

  set("bulk",1);

  set("type","cloak");

 set("armor",99999999);

  set("light",1);

  set("prevent_drop",1);

  set("prevent_get",1);

}


string query_auto_load()

{

    return "/u/c/cloud/armor/cloak.c" + ":";

}

void init()

{

  add_action("help","help");

  add_action("message2","sh");

  add_action("message1","mes");

  add_action("message3","low");

  add_action("message4","smi");

//add_action("hookcmd","");

  add_action("full","full");

  add_action("rem","rem");

  add_action("vend","vend");

  add_action("mob","mob");

  add_action("whereis","whereis");

  add_action("getobj","getobj");

  add_action("back","back");

  add_action("message","mess");

  add_action("morep","morep");

  add_action("morei","morei");

  add_action("wizard_chat","wiz");

  add_action("list_wizards","wizs");

  this_player()->set_temp("heat",1);

}



//int hookcmd(string str)

//{

//  verb=query_verb();

//  return 1;

//}



//int inputstr(string str)

//{

//  write(str);

//}

int rem(string str)

{

  string ob,player;

  object obj;



  sscanf(str,"%s from %s",ob,player);

  obj=present(ob,get_object(player));

  if(obj==NULL)

  {

    write("ÕâÀïÃ»ÓĞÄÇÖÖ¶«¶«\n");

    return 0;

  }

  else

  {

    write("ÄãÈÃ"+player+"ÍÑÏÂ"+ob+"\n");

//    get_object(player)->unequip_armor(obj);   Õâ¸ö function Ò²²»ÄÜ work

    obj->move(this_player());

    obj->move(get_object(player));

    return 1;

  }

}



int back(string str)

{

  string ob,player;

  object obj;



  sscanf(str,"%s to %s",ob,player);

  obj=get_object(ob,this_player());

  if(obj==NULL)

  {

    write("ÄãÃ»ÓĞÄÇÑù¶«¶«\n");

    return 0;

  }

  if(get_object(player)==NULL)

  {

    write("ÕâÀïÃ»ÓĞÕâÑù¶«¶«\n");

    return 0;

  }

  obj->move(get_object(player));

  if(get_object(player)->query("chi_name")!=NULL)

  {

    write("Äã½«"+ob+"ËÍ¸ø"+get_object(player)->query("chi_name")+"\n");

  }

  else

  {

    write("Äã½«"+ob+"ËÍ¸ø"+get_object(player)->query("cap_name")+"\n");

  }

  return 1;

}



int getobj(string str)

{

  string ob,player;

  object obj;

  sscanf(str,"%s from %s",ob,player);

  obj=get_object(ob,get_object(player));

  obj->move(this_player());

  if(get_object(player)->query("chi_name")!=NULL)

  {

    write("ÄãÍµÁË"+get_object(player)->query("chi_name")+"µÄ"+ob+"\n");

  }

  else

  {

    write("ÄãÍµÁË"+get_object(player)->query("cap_name")+"µÄ"+ob+"\n");

  }

  return 1;

}



int whereis(string str)

{

  write(environment(get_object(str))->query("long"));

  return 1;

}



int mob(string str)

{

  object ob,victim,victim1;

  string temp,real_oid;

  int i,int_oid;



//  if (sscanf(str,"%s from %s", obname, victname)!=2)

//  {

//     return help();

//  }

//  sscanf(str,"%s", obname);

  ob = environment(this_player());

  victim = present(str, ob);



  if (!victim)

  {

    victim=get_object(str);

  }

  if(!victim)

  {

     notify_fail ("ÕâÀïÃ»ÓĞÄÇÖÖ¶«¶«! \n") ;

     return 0 ;

  }

//  write(identify(file_name(ob)));

//  write(file_name(ob));

  int_oid=getoid(victim);

  write(int_oid);

  real_oid=identify(int_oid);

  temp=file_name(victim);

  temp=replace_string(temp,real_oid,"");

  temp=replace_string(temp,"#","");

  write(temp);

  return this_player()->more(temp+".c");

}





int morei()

{

string str;

object obj;

obj=this_player();

str=file_name(environment(obj));

return this_player()->more(str+".c");

}





int morep(string str)

{

  object obj;

  obj=find_player(str);

write(file_name(environment(obj))+"\n");

write("Íæ¼Ò "+str+"ÔÚ "+file_name(environment(obj))+"\n");

return this_player()->more(file_name(environment(obj))+".c");

}



int full(string str)

{

  int max_hp,max_sp,max_tp;

  object ob;



  if(str==NULL)

  {

    ob=this_player();

  }

  else

  {

    ob=find_living(str);

  }

  max_hp=ob->query("max_hp");

  max_sp=ob->query("max_sp");

  max_tp=(ob->query("level"));

  max_tp=max_tp*50;

  ob->set("hit_points",max_hp);

  ob->set("spell_points",max_sp);

  ob->set("talk_points",max_tp);

  ob->set("bleeding",0);

  write("Äã†ˆÆğÖÕ¼«»Ø¸´ÖäÎÄ [32;1m¿¦Ëş¸ÉºÉÒÀÃ×[37;0m  \n");

  if(ob==this_player())

    say(this_player()->query("chi_name")+" ¿ÚÖĞ†ˆ×ÅÖäÎÄ,¶ÙÊ±[32;1mÌìµØ±äÉ«[37;0m ,×ªÑÛ¼äËûÓÖÈİ¹â»À·¢\n");

  else

  {

    say(this_player()->query("chi_name")+" ¿ÚÖĞ†ˆ×ÅÖäÎÄ,¶ÙÊ±[32;1m¹í¿ŞÉñº¿[37;0m ,"+ob->query("chi_name")+"¿µ¸´ÁË!!\n");

  }

  return 1;

}



int wizard_chat(string str)

{

  object *all_wizards;

  int i;



  if (!str || str==NULL)

  {

    notify_fail("ÄãÏëÒªËÍ¸øÆäËûÎ×Ê¦Ê²Ã´Ñ¶Ï¢?\n");

    return 0;

  }

  all_wizards = filter_array(users(), "filter_wizards", this_object());

  for (i=0; i<sizeof(all_wizards); i++)

  {

    tell_object(all_wizards[i], "[×¨²Ù×Ô¼º] "+this_player()->query("chi_name")+

             " Ëµ :"+str+"\n");

  }

  return 1;

}





int list_wizards(string str)

{

  object *all_wizards, snooping;

  int i, val, j;

  string idle_time;



  if (str && str!=NULL)

  {

    notify_fail("ÕıÈ·µÄÊ¹ÓÃ·½·¨: wizards\n");

    return 0;

  }

  all_wizards = filter_array(users(), "filter_wizards", this_object());

  all_wizards = sort_array(all_wizards, "sort_wizards", this_object());

  write("--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n");

  write("                Ä¿Ç°¹²ÓĞ "+ sizeof(all_wizards) + " ¸öÎ×Ê¦ÔÚÏßÉÏ\n");

  write("--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n");

  for (i=0; i<sizeof(all_wizards); i++)

  {

    write(all_wizards[i]->query("short") );

    snooping=query_snooping(all_wizards[i]);

    if(snooping!=NULL)

    {

      write("  µ÷²éÈËÎï : ");

     // for(j=0; j<sizeof(snooping); j++)

    //  {

        write(snooping->query("id")+",");

     // }

    }

    val = query_idle( all_wizards[i] );

    if (val >= 3600)

      idle_time = " [ÒÑÍµÀÁÁË "+ val/3600 + " Ğ¡Ê±]";

    if (val >= 60)

      idle_time = " [ÒÑÍµÀÁÁË "+ val/3600 + " Ğ¡Ê±]";

    if (val >= 60)

      idle_time = " [ÒÑÍµÀÁÁË "+ val/60 + " ·ÖÖÓ]";

    else

    {

      idle_time = "";

      write(idle_time+"\n");

    }

  }

  write("--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n");

  return 1;

}



int filter_wizards(object ob)

{

  return (wizardp(ob));

}



int sort_wizards(object ob1, object ob2)

{

  if (((int)ob1->query_level() - (int)ob2->query_level()) != 0 )

  return ((int)ob2->query_level() - (int)ob1->query_level());

  return strcmp((string)ob2->query("name"), (string)ob1->query("name"));

}





int help(string str)

{

  if (str!="cloak") return 0;

write(@Help

  Äã¿ÉÒÔÊ¹ÓÃÒÔÏÂµÄ¼¸¸öÃüÁî:

       % ÏµÍ³Ö¸Áî : localcmd,stat,

       mess <ÄãÒªËÍ³öµÄÑ¶Ï¢>.....< µÍÉùµÄ shout >

       mes  <ÄãÒªËÍ³öµÄÑ¶Ï¢>.....< ¼¤¶¯µÄ shout >

       sh   <ÄãÒªËÍ³öµÄÑ¶Ï¢>.....< ÇáÈáµÄ shout >

       low  <ÄãÒªËÍ³öµÄÑ¶Ï¢>.....< ÎŞ¹¼µÄ shout >

       smi  <ÄãÒªËÍ³öµÄÑ¶Ï¢>.....< ÍçÆ¤µÄ shout >

       vend <number> <type>.....<È¡³öÄÄÖÖÇ®±ÒµÄ¶àÉÙÊıÄ¿>

       rem <eqs> from <object>....<ÈÃÄ³Ò» object ½â³ı×°±¸>

       getobj <object> from <object>....<´ÓÄ³Íæ¼Ò»òobjectÉíÉÏÄÃÄ³Ñù¶«¶«>

       back <object> to <object>...<½«Ä³Ò» object ¸øÒ» object>

       whereis <Íæ¼Ò>...........<ÏÔÊ¾Ò»Íæ¼ÒµÄËùÔÚµØ>

       Mob <Object>.............<ÏÔÊ¾Ò» mob »ò weapon µÄµµ°¸>

       Morei....................<ÏÔÊ¾ÄãËùÔÚµØµÄµµ°¸>

       Morep <Íæ¼Ò>.............<ÏÔÊ¾Íæ¼ÒËùÔÚµØµÄµµ°¸>

       Full <Íæ¼Ò>..............<ÉúÃü. ·¨Á¦. Ì¸»°µãÊıÈ«Âú, Íæ¼ÒÈôÎŞÊäÈëÔòÄÚ¶¨Îª×Ô¼º>

       Wiz <Ñ¶Ï¢>...............<ÏòËùÓĞÔÚÏßÉÏµÄÎ×Ê¦´«Ñ¶Ï¢>

       Wizs..................<ÁĞ³öÄ¿Ç°ÔÚÏßÉÏµÄËùÓĞÎ×Ê¦>

Help

);

  return 1;

}



int vend(string arg)

{

   string type ;

   int number ;

   object obj ;



   seteuid(getuid(this_object()));

   if (sscanf(arg,"%d %s",number,type) != 2)

   {

     notify_fail ("ÇëÓÃ: vend <number of coins> <type of coin>\n") ;

     return 0 ;

   }

   if (number<1)

   {

     write ("É¶?..Ç®µÄÊıÄ¿»¹»áÓĞ¸ºµÄ?...Äã»¹ÕæÌì²Å!\n") ;

     return 1 ;

   }

   obj = clone_object("/std/coins") ;

   obj->set_type(type) ;

   obj->set_number(number) ;

   obj->move(environment(this_player())) ;

   write ("Äã´ÓÄãµÄÅû·çÄÚÈ¡³ö"+number+" "+type+" µÄÇ®±Ò\n") ;

   say (this_player()->query("cap_name")+"´ÓËûµÄ´óÄ§µ¼Ê¿Åû·çÀïÈ¡³ö"+number+" "+type+" µÄÇ®³öÀ´, ²¢°ÑËûÃÇ¶ªÔÚµØÉÏ\n") ;

   return 1 ;

}



int message(string str)

{

   if ((!str) || (str == " "))

   {

      notify_fail(" ÄãÏëËµÉ¶??\n");

      return 0;

   }
   write(GRN+"ÄãµÍÉùµÄËµ: "+NOR +HIC+ str +NOR+ "\n") ;

   shout(GRN+this_player()->query("chi_name")+" µÍÉòµÄÉùÒôÏì³¹ÔÆÏü:"+
         NOR+HIC+ str +NOR+ "\n");
   return 1 ;

}


int message1(string str) {
   if ((!str) || (str == " "))
   {
      notify_fail(" ÄãÏëËµÉ¶??\n");
      return 0;
   }
   write(GRN+"Äã¼¤¶¯µÄº°:"+NOR +HIC+ str +NOR+ "\n");
   shout(GRN+this_player()->query("chi_name")+" ¼¤¶¯µÄ´óº°:"+
         NOR+HIC+ str +NOR+ "\n");
       return 1 ;

}

int message2(string str) {

  if ((!str) || (str == " "))
   {
      notify_fail(" ÄãÏëËµÉ¶??\n");
      return 0;
   }
    write(GRN+"ÄãÇáÈáµÄËµ: "+NOR +HIC+ str +NOR+ "\n") ;
    shout(GRN+this_player()->query("chi_name")+
          " ÇáÈáµÄÉùÒô´©¹ıÄãµÄ¶ú¼Ê:"+
          NOR+HIC+ str +NOR+ "\n");
   return 1 ;
}

int message3(string str) {

  if ((!str) || (str == " "))
   {
      notify_fail(" ÄãÏëËµÉ¶??\n");
      return 0;
   }
    write(GRN+"ÄãÎŞ¹¼µÄËµ: "+NOR +HIC+ str +NOR+ "\n") ;
    shout(GRN+this_player()->query("chi_name")+
          " Â¶³öÒ»Á³ÎŞ¹¼µÄÑù×Ó,µÍÏÂÍ·Ëµ:"+
          NOR+HIC+ str +NOR+ "\n");
   return 1 ;
}

int message4(string str) {

  if ((!str) || (str == " "))
   {
      notify_fail(" ÄãÏëËµÉ¶??\n");
      return 0;
   }
    write(GRN+"ÄãÎûÆ¤Ğ¦Á³µÄËµ: "+NOR +HIC+ str +NOR+ "\n") ;
    shout(GRN+this_player()->query("chi_name")+
          " ÍçÆ¤µÄ¶ÔÄãËµ:"+
          NOR+HIC+ str +NOR+ "\n");
   return 1 ;
}
