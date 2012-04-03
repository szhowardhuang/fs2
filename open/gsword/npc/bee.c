inherit NPC;

void create()
{
	set_name("蜜蜂", ({ "bee" }) );
	set("race", "野兽");
	set("age", 1);
	set("long", "一只正在采蜜的蜜蜂.\n");
	set("str", 15);
	set("cor", 25);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "头部", "身体", "前脚" , "后脚" , "尾巴" }) );
	set("combat_exp",150);
	// 设定 random_move 能离开家的步数
	set("random_move",5);
	set("chat_chance",10);
	set("chat_msg", ({
	    (: this_object(),"random_move" :),
	               }) );
	set_skill("dodge",10);
	setup();               

}

