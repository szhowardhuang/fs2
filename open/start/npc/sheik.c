//sheik.c

#include <room.h>
#include <../start.h>
#include <ansi.h>

inherit F_VENDOR;

string do_rest();
// string give_letter();

void create()
{
	set_name("村长",({"sheik"}) );
	set("long","一个看起来非常平凡的人，平凡到你根本不会想知道他\n的名字，如果你累了，可以问他有关休息(rest)的事。\n");
	set("gender","男性");
	set("age",47);
	set("combat_exp", 98);

	set("inquiry",([
	"rest":(: do_rest :),
	"休息":(: do_rest :),
	/* "跑腿":"我想找个人帮我把信送到平南城去，你有空吗？\n",
	"平南城":"你从东村口出去以后走到岔路口往南走就会找到了。\n",
	"letter":(: give_letter :),
	"信":(: give_letter :), */
	]));

	set("vendor_goods", ({
		S_OBJ"thunder_hat",
		S_OBJ"rain_cloth",
		"/obj/example/dumpling",
	}) );
/*
	set("chat_chance", 5);
	set("chat_msg", ({
		"村长摸着头说：有没有人愿意帮我跑腿呢？\n"}) );
*/
	setup();
}

void init()
{
	add_action("do_vendor_list","list");
	// add_action("do_report","report");
}

int accept_fight(object me)
{
	return notify_fail("村长摇摇头对你说：请不要打扰我们好吗？\n");
}

string do_rest()
{
	object who;
	string str;

	who = this_player();
	str = "休息一次五两黄金，\n";
	if( !who->can_afford(50000) ) {
		str += "钱不够啊！那就对不起了。\n";
		return str;
	}
	else {
                who->pay_money(50000);
		who->set_temp("sleep", 1);
		message_vision("$N付给村长一笔钱。\n", who);
		str += "嗯，你可以过去西面那客房休息。\n";
		return str;
	}
}
/*
string give_letter()
{
	object who;
	who = this_player();

	if( who->query("quests/letter") )
		return "村长笑着对你说：谢谢你上次帮我送信。\n"
	if( who->query_temp("letter") )
		return "怎么样？信送到了没？\n";
	else {
		new(S_OBJ"letter")->move(who);
		message_vision("村长从怀里拿出一封信交给$N。\n", who);
		who->set_temp("letter", 1);
		return "请你帮我把这封信送去给平南城的王老板，谢谢。\n对了！你可千万不可以看信的内容喔！\n";
	}
}

int do_report(string arg)
{
	object who;
	who = this_player();

	if( !arg || arg!="sheik" )
		return notify_fail("你要回报给谁？\n");
	if( who->query("quests/letter") )
		return notify_fail("村长笑着说：谢谢你上次帮我送信。\n");
	else if( who->query_temp("letter")==2 ) {
		tell_object(who,"村长高兴的对你说：辛苦你了，"+RANK_D->query_respect(who)+"，你累的话可以进去休息一下。\n");
		who->set("sleep", 1);
		who->set("quests/letter", 1);
		who->add("combat_exp", 30);
		tell_object(who,HIY"你完成‘村长的信’任务了！\n"NOR);
		tell_object(who,HIC"你的经验增加了！\n"NOR);
		return 1;
	}
	else if( who->query_temp("letter")==4 )
		tell_object(who,"村长高兴的对你说：辛苦你了。\n");
	else
		return notify_fail("村长皱着眉头对你说：有事吗？\n");
}
*/
