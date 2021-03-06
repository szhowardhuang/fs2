// monkey.c by powell

inherit NPC;

void create()
{
        set_name("猴子", ({ "monkey" }) );
        set("long", "一只好动的猴子，东摸摸西摸摸，没有一刻停下来过。\n");

	set( "age", 30);

        set("str", 30);
        set("cor", 30);

        set("combat_exp", 1000);

        set("race", "野兽");

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
		"小猴子：吱吱..吱吱...\n",
 		"小猴子们躲在树丛里, 偷偷的望着你这个闯入者。\n",
 	}) );
	
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 10);
	
	set_skill("dodge",30);
	set_skill("unarmed",30);
	
        setup();
}

