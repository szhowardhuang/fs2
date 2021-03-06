// m-king.c by powell

inherit NPC;

void create()
{
        set_name("猴子王", ({ "monkey king", "king" }) );
        set("long", "一只威武的大猴子，站起来比你还高。\n"+
                    "看来牠是这谷中的领导者。\n");

	set( "age", 150);

        set("str", 130);
        set("cor", 30);

	set( "force_factor", 3 );
	set( "force", 1000 );
	set( "max_force", 1000);

        set("combat_exp", 10000);

        set("race", "野兽");

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("attitude", "friendly");

        set("chat_chance", 2);
        set("chat_msg", ({
		"吱吱..吱吱...\n",
		"猴子王张大牠的双眼, 瞧了瞧你。\n",
 		"猴子王对着你吱吱的叫了几声, 好像要告诉你些甚么..\n",
        }) );
	
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 20);
	
	set_skill("dodge",80);
	set_skill("unarmed",80);
	
        setup();
}

