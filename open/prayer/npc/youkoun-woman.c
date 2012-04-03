//ºì¹Ã
#include <command.h>
 
inherit NPC;

string ask_book();

void create()
{
    set_name("¸¾Å®",({"woman"}));
    set("gender", "Å®ĞÔ");
    set("age",35);
    set("attitude","friendly");
    set("long",@LONG

	ËıÊÇÏ¼É½ÅÉµÄÅ®µÜ×Ó, ³¤ÄêÇÇ×°¶ãÔÚ´ËµØ!!

LONG);
 
    set("combat_exp",522000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("dodge",130);
    set_skill("move",130);
    set_skill("parry",130);
    set_skill("whip",130);
    set_skill("force",130);
    set_skill("sunwhip",130);
    set_skill("fireforce",130);
    map_skill("force", "fireforce");
    map_skill("whip", "sunwhip");
    map_skill("parry", "sunwhip");
    set("inquiry",([
    "Ï¼É½ÅÉ":"[36mÏ¼É½ÅÉµÄÎäÑ§Â·Êı, ÏµÊ¦×æËù´´Ö®[ÂäÈÕ±Ş·¨]![0m\n",
    "ÃÜóÅ":(: ask_book :),
    "ÑàÊ®Ò»":"Ëû.....ÊÇÎÒµÄÍ¬ÃÅÊ¦µÜ!!²»¹ı±»ÖÜ¬Lò¯Â°È¥ÁË....\n",
    "ÖÜ¬Lò¯":"Ëı¾ÍÊÇÏÖÈÎÊ¥»ğ°ËÌìÃÅÖ®Ò»--Ñş¹âÃÅµÄÃÅÖ÷!!\n",
 ]));
    setup();
    carry_object("/open/prayer/obj/whip1")->wield();
    add_money("gold", 2);
}

void init()
{
	object who;
	::init();
	if(interactive(who =this_player()) && !is_fighting() )
	{
	remove_call_out("greeting");
        call_out("greeting",2,who);
        add_action("do_nod","nod"); 
        }
}

int do_nod()
{
	object who=this_player();
	if( who->query_temp("red") == 1  )
	{
	return 0;            
	}
	else
	{
	who->set_temp("help_red", 1);
        write("[36màÅ!!ÄÇÎÒµÈÄãµÄºÃÏûÏ¢!!ÍòÊÂ°İÍĞÁË[0m\n");
        return 1;
        }

}

void greeting(object who)
{
    if( who->query_temp("kill_red") >= 1 ) 
    {
      if( who->query_temp("red") >= 1 )
      {
      write("\n[36mÄãÒ»¶¨ÊÇÑàÊ¦µÜÅÉÀ´µÄÈË°É!!Ï£ÍûÄãÄÜÖúÎÒÒ»±ÛÖ®Á¦, ²ù³ıÖÜ¬Lò¯
    Õâ¸ö¶ñ¶¾µÄÅ®ÈË!!ºÃÂğ(nod)??[0m\n");
      who->set_temp("red", 2);
      }
      else
      {
      write("\n[31mÎÒÖªµÀÄãÊÇÖÜ¬Lò¯ÄÇ¸öÍü¶÷¸ºÒåµÄÅ®ÈËÅÉÀ´µÄ!!»¹ÎÒÊ¦µÜÀ´!![0m\n");
      kill_ob(who);
      }
    }
    return;
}


string ask_book()
{
    object who=this_player();
    object ob3=new("/open/prayer/obj/whipbook");
    if( who->query("quests/sunwhip",1) && !present("whipbook",who) )
    {
    ob3->move(this_player());
    return "[36mÄã×Ô¼ººÃºÃµØ´§Ä¦´§Ä¦°É!!ÓĞ³¯Ò»ÈÕ¿ÉÒÔÓÃÀ´·ÀÉíÉ±µĞ[0m\n";
    }
    else
    {
    return "[36m±¾ÃÅÎäÑ§ÃÜóÅÆñ¿ÉÇáÒ×ÍâĞ¹²ØÄäÖ®´¦!![0m\n";
    }
}   

void die()
{

    object who;
    who= this_object()->query_temp("last_damage_from");
    if( who && userp(who) ) 
    {
    who->delete_temp("kill_red");
    who->set_temp("kill_red", 2);
    write("[36mÎÒËÀÁËÖ®ºó, Ï£ÍûÄãÄÜÌæÎÒ×ª¸æÊ¦µÜÑàÊ®Ò», Ëû»á¸æËßÄãÃÜóÅµÄÏÂÂäµÄ!![0m\n");
    }
    ::die() ;
}


