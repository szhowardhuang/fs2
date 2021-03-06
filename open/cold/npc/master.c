// shiao.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("意映",({"master yin","yin"}));

	set("nickname","九华龙仙");
	set("gender", "男性");
	set("age",20);
	set("long",
		"她是一位精通仙法的为武林异人，相传是「九华仙女”投胎转世，法术骇为惊人。\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);

	set("force",800);
	set("max_force",800);
	set("force_factor",10);

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	}) );

	set_skill("unarmed",40);
	set_skill("sword",70);
	set_skill("force",60);
	set_skill("magic",100);
	set_skill("literate",90);
	set_skill("dodge",100);
	set_skill("parry",40);
	create_family("玄冰寒谷",3,"掌门人");

	setup();

}

void init()
{
	add_action("do_touch","touch");
}

void attempt_apprentice(object me)
{
	if(me->query("gender")!="女性")
	{
		command("say 对不起 ! 本姑娘向来只收女徒。\n");
		return;
	}
	command("l "+me->query("id"));
	if(me->query("per")<20)
	{
		command("say 很抱歉 ! 妳我并无师徒缘分。");
		return;
	}
	if(me->query_temp("do_touch_yin")!=1)
	{
		command("say 小姑娘，过来摸我的手。\n");
		return;
	}
}
int do_recruit(object me)
{
	command("smile "+me->query("id"));
	command("say 我最喜欢像你这样的女孩了。\n");
	command("recruit "+me->query("id"));
	return 1;
}


int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_availavble", -1);
}
int do_touch(string arg)
{
	if(this_player()->query("gender")!="女性")
		return notify_fail("你想干嘛 ?\n");
	if(arg!="yin")
		return notify_fail("你在摸什么 ?\n");
	message_vision("$N伸出了手，轻轻的摸了$n的脸。\n",this_player(),this_object());
	command("smile");
	this_player()->set_temp("do_touch_yin",1);
	if(this_player()->query("per")>20)
		do_recruit(this_player());
	return 1;
}
