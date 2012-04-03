#include <ansi.h>
#include <command.h>
#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("°×ÒÂÈË",({"white man","man"}));
    set("gender", "ÄÐÐÔ");
    set("age",65);
    set("attitude","peaceful");
    set("long",@LONG

        ËûÊÇÒøÕëÃÅ²Ø¾­¸óÉñÃØºÚÒÂÀÏÈËµÄµÜ×Ó, ÅÅÐÐµÚÈý!!¾«Í¨½£Êõ!!

LONG);

    set("combat_exp",100000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",5000000);
    set("kee",5000000);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("sixforce",60);
    map_skill("force", "sixforce");
    set_skill("sword",60);
    set_skill("shasword",60);
    map_skill("sword", "shasword");
    setup();
    carry_object("/open/gsword/obj/woodsword")->wield();
}
void greeting(object ob)
{
        if( ob->query("red") ==1 ) 
        {
        command("say ·îÊ¦×ðÖ®ÃüÓëÉÙÏÀÇÐ´è¼¸ÕÐ!!");
        kill_ob(ob);
        message_vision("[1;31mËûÍ»È»¿ñÐÔ´ó·¢, ½ô½Ó×ÅÒ»½£´Ì´©ÁËÄãµÄÐØÌÅ .... [0m\n",ob);
        message_vision("\n",ob);
        tell_object( ob ,"[1;31mÄãµÄÑÛÇ°Ò»Æ¬ºÚ°µ......[0m\n");
        this_object()->remove_all_killer();
        ob->unconcious();
        load_object("/open/doctor/room/book6");
        ob->move("/open/doctor/room/book6");
        ob->set("white",1);
        ob->delete("red");
        }
        
}
