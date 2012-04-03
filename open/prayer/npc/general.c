#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("教头",({"general"}));
    set("gender", "男性");
    set("age",33);
    set("attitude","peaceful");
    set("long",@LONG

	圣火教的教头, 由每三年所举行的比武大会中挑选而出的
	教徒. 负责督导门生的武学!!

LONG);
 
    set("combat_exp",90000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("force",900);
    set("max_force",900);
    set("force_factor",5);
    set("max_kee",450);
    set("kee",450);
    set("limbs",({"头","手","脚","背","腹","腰"}));
    set_skill("force",50);
    set_skill("universe",50);
    set_skill("unarmed",50);
    set_skill("superforce",50);
    set_skill("move",55);
    set_skill("shift-steps",55);
    set_skill("parry",55);
    set_skill("dodge",60);
    map_skill("move","shift-steps");
    map_skill("parry","universe");
    map_skill("unarmed","universe");
    map_skill("dodge","shift-steps");
    map_skill("force","superforce");
 
    setup();
    add_money("silver",50);
    carry_object("/open/prayer/obj/wind-robe")->wear();
    carry_object("/open/prayer/obj/wind-boots")->wear();

}

