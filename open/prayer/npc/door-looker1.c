#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("ÊØÃÅµÜ×Ó",({"door-looker","looker"}));
    set("gender", "Å®ĞÔ");
    set("age",26);
    set("attitude","friendly");
    set("long",@LONG

	Ñş¹âÃÅ´óÃÅµÄÊØÎÀ, Ö°Ôğ±ãÊÇ¹ıÂËÓĞÎŞÏĞÔÓµÄÄĞĞÔ
	»ì½øÑş¹âÃÅ!!²¢ÑÏ¸ñÖ´ĞĞ´ËÒ»ÈÎÎñ.

LONG);
 
    set("combat_exp",40000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",500);
    set("kee",500);
    set("limbs",({"Í·","ÊÖ","½Å","±³","¸¹","Ñü"}));
    set_skill("universe",30);
    set_skill("force",50);
    set_skill("superforce",50);
    set_skill("move",55);
    set_skill("shift-steps",50);
    set_skill("unarmed",50);
    set_skill("parry",50);
    set_skill("dodge",50);
    map_skill("unarmed","universe");
    map_skill("move","shift-steps");
    map_skill("dodge","shift-steps");
    map_skill("parry","universe");
    map_skill("force","superforce");
 
    setup();
    add_money("gold",1);
    carry_object("/open/prayer/obj/wind-robe")->wear();
    carry_object("/open/prayer/obj/wind-boots")->wear();
}

int accept_fight(object who)
{
    return notify_fail("ÊØÃÅµÜ×ÓËµµÀ:ÎÒÔÚÖµÇÚÒ®!! ²»ÒªÀ´·³ÎÒÀ²!!");
}

void greeting(object who)
{
    if( who->query_temp("ÉÃ´³ĞÌ·¿",1) )
    {
    write("[31mÖÜÃÅÖ÷ÒÑ¾­ÏÂÁËÍ¨¼©Áî, ÒªÄÃÄãµÄÈËÍ·À´¼û!![0m\n");
    kill_ob(who);
    return;
    }

    if( (who->query("family/family_name") == "Ê¥»ğ½Ì") )
    {
    write("\n\t[36mÄĞµÜ×Ó¿ÉµÃ´ø½ÌÖ÷ÁîÅÆ²ÅÄÜ½øÈ¥à¸!![0m\n");
    return;
    }


    return;
}
