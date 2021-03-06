// old_buffalo.c by oda

inherit NPC;

void create()
{
	set_name("老水牛", ({ "Old buffalo", "buffalo" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只年迈的老水牛，因为不用工作而在田里闲晃着。\n");

	set("str", 17);
	set("con", 15);
	set("max_gin", 120);
	set("max_kee", 110);
	set("max_sen", 100);

	set("limbs", ({ "身体", "头部", "前脚", "后腿", "尾巴" }) );
	set("verbs", ({ "hoof", "bite", "dunt" }) );

	set("chat_chance", 12);
	set("random_move",2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"老水牛抬起头来看看你，接着又低下头继续吃草去了，一副懒得理你的样子。\n"}) );
		
	set("combat_exp", 32);

	setup();
}
