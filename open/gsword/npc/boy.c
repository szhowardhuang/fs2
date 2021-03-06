inherit NPC;
void create()
{
	set_name("小童", ({"clean boy","boy"}));
	set("long","仙剑派的小童,在这儿忙得昏头转向,因为受了师父陆正清的命令,
要把这儿所有的防具给擦拭干净,小孩子哪敢违背师父的命令,只好
拿着小油布拼命的擦拭着.\n");
	set("gender","男性");
	set("combat_exp",1000);
        set("attitude","friendly");
	set("age",15);
	set("title","仙剑派小童子");
	set("score",1000);
	set("force",0);
	set("max_force",0);
	set_skill("force",5);
        set_skill("shasword",4);
	set_skill("sword",7);
	set_skill("dodge",10);
	set_skill("parry",6);
	set_skill("literate",15);
	set_skill("unarmed",10);
	set_skill("blade",7);
	set_skill("dagger",5);
        set("str", 20);
        set("cor", 26);
	set("per", 20);
	set("int", 15);
	set("cps", 10);
	set("con", 20);
	set("spi", 15);
	set("kar", 15);
	setup();
	carry_object("/open/gsword/obj/suit")->wear();
	add_money("coin",50);
}

