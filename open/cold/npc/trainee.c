// bandit.c

inherit NPC;

void create()
{
	set_name("小诗",({"poet"}));
	set("gender","女性");
	set("nickname","楚楚动人");
	set("age",14);
	set("long",
		"他是寒谷一派弟子中最年轻的弟子，名曰小诗，她的资质优异，极得师父清雪的喜爱。\n");
	set("combat_exp",5000);
	set("score", 60);
	set("attitude","heroism");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("force",30);
	set_skill("magic",40);
	set_skill("dodge",60);
	setup();
	add_money("silver", 3);
	create_family("玄冰寒谷",5,"弟子");
}
