#include <ansi.h>
inherit NPC;


void create()
{
	set_name("筑颖",({"truin"}) );
        set("long","她和筑依一样，从小就被弃于昆仑山中，后来被陆清风带回扶养，
进了天道。\n");
        set("gender","女性");
        set("class","taoist");
	set("combat_exp",40000);
        set("age",18);
	 set("title","天道派第三代弟子");
        set("str", 15);
        set("cor", 30);
        set("cps", 30);
        set("per", 30);
        set("spi", 30);
        set("int", 26);
        set("force", 200);
        set("max_force", 200);
        set("max_mana",200);
        set("max_atman",150);
	set("max_kee",6000);
	set("kee",6000);

	
        setup();
	add_money("gold",1);
}

