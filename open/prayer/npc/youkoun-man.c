//ÑàÊ®Ò»
#include <command.h>
 
inherit NPC;

string ask_red()
{
    object who=this_player();
    if( who->query_temp("youkoun") >= 4 )
    {
    who->set_temp("red",1);
    return("[36mËıÏÖÔÚÔÚÄÇÀïÎÒÒ²²»ÖªµÀ, ²»¹ıÎÒÔÚÄãÉíÉÏÒÑ¾­×öÁË¼ÇºÅ, Ö»ÒªËıÒ»¼ûµ½¾Í»á·¢ÏÖÁË!![0m\n");
    }
    else
    {
    return("[36mÏàĞÅÄãÒÑ¾­´ÓÖÜ¬Lò¯ÄÇÀïÌıµ½²»ÉÙ¶«Î÷ÁË°É!![0m\n");
    }
}

string ask_whip()
{
    object who=this_player();
    if( who->query_temp("kill_youkoun") && who->query_temp("help_red") && !who->query("quests/sunwhip"))
    {
    who->set("quests/sunwhip",1);
    who->set_skill("sunwhip",5);
    who->add("max_force",50);
    return("[36mÄã°ïÁËÎÒ¾ÍµÈÓÚÊÇ°ïÁËÏ¼É½ÅÉÁË!!ÕâÂäÈÕ±Ş·¨¾Í´«ÁËÄã°É!![0m\n");
    }
    else
    {
    return("[36mÂäÈÕ±Ş·¨ÊÇ²»ÄÜ¹»Ëæ±ã¾Í´«ÊÚËûÈËµÄ!!Äú»¹ÊÇ²»Òª´òËüµÄÖ÷Òâ°É!![0m\n");
    }
}

void create()
{
    set_name("ÑàÊ®Ò»",({"man-eleven","man","eleven"}));
    set("title", "Ï¼É½");
    set("gender", "ÄĞĞÔ");
    set("age",32);
    set("attitude","friendly");
    set("long",@LONG

	Ï¼É½ÅÉµÜ×Ó--ÑàÊ®Ò», Òò¹Ê±»ÇôÓÚ´Ë, È«ÉíÉËºÛÀÛÀÛ
	²»¹ıÑÛÉñÖĞÈÔÊÇÍ¸³öÒ»¹É¾«×³Ö®¹â.........

LONG);
 
    set("combat_exp",432000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",500);
    set("kee",500);
    set("max_force",500);
    set("force_factor", 25);
    set("force",500);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("dodge",150);
    set_skill("move",150);
    set_skill("parry",150);
    set_skill("whip",120);
    set_skill("sunwhip",120);
    set_skill("force",120);
    set_skill("fireforce",120);
    map_skill("force", "fireforce");
    map_skill("whip", "sunwhip");
    map_skill("parry", "sunwhip");
    set("inquiry",([
    "Ï¼É½ÅÉ":"[36mÏ¼É½ÅÉµÄÎäÑ§Â·Êı, ÏµÊ¦×æËù´´Ö®[ÂäÈÕ±Ş·¨]![0m\n",
    "ÃØóÅ":"[36mÃØóÅ²ØÔÚºì¹ÃÄÇÀï!!²»¹ıÎÒ±»À§ÓÚ´ËÃ»ÈËÖªµÀ!![0m\n",
    "ÂäÈÕ±Ş·¨":(: ask_whip :),
    "ºì¹Ã":(: ask_red :),
 ]));
    setup();
    carry_object("/open/prayer/obj/ligature")->wield();
}

void greeting(object who)
{
    if( who->query_temp("kill_red") >= 2 ) 
    {
    write("    [36mÄã¾¹È»É±ÁËÎÒÊ¦½ã, »¹ÏëÒªÎÒÅÉ±Ş·¨µÄÃÜóÅ!!ºß!!Ï¼É½ÅÉ´Ó´ËÓë
    ÄãÓÀÎŞÄşÈÕ!!ÎÒÏÖÔÚ¾ÍÏÈ¸úÄãÆ´ÁË!!\n");
    kill_ob(who);
    return;
    }
}

void die()
{

    object who;
    who= this_object()->query_temp("last_damage_from");
    if( who && userp(who) ) 
    {
    who->set("kill_eleven", 1);
    write("\n[36mĞ»Ğ»ÄãÉ±ÁËÎÒ, ÎÒÔÚÏÂÃæ¿ÉÒÔ¿ìÀÖµØ¸úÊ¦½ãÔÚÒ»ÆğÁË!![0m\n");
    }
    ::die() ;
}
