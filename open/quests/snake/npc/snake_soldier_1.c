inherit NPC;
#include <ansi.h>

void create()
{
	set_name("蛇寨护卫",({"snake-soldier","snake","soldier"}));
	set("age",20);
	set("gender","男性");
        set("attitude","aggressive");
	set("long","
蛇寨的护卫，专门抵挡闯入蛇寨的人，心狠手辣，毫不留情。\n");
	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);
	set("max_force",7000);
	set("force",7000);
	set("force_factor",10);
	set("combat_exp",400000);
	set_skill("whip",100);
	set_skill("snake-whiper",100);
	set_skill("parry",100);
	set_skill("dodge",100);
	set_skill("move",100);
	set_skill("black-steps",100);
	set_skill("force",100);
	set_skill("snowforce",100);
	map_skill("whip","snake-whiper");
	map_skill("parry","snake-whiper");
	map_skill("dodge","black-steps");
	map_skill("move","black-steps");
	map_skill("force","snowforce");
	setup();
	carry_object(__DIR__"obj/whip")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void die()
{
object me,ob,obj;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

	if( random(100) < 30 )
	{
		obj = new(__DIR__"obj/snake-key-1");
		message_vision(HIY"$N抵挡不住$n的攻击～急急忙忙的逃命跑走了...
在跑走的时候，不小心遗落了东西。\n"NOR,ob,me);
		obj->move(environment(me));
		destruct(ob);
	}
::die();
}