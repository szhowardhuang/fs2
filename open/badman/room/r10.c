// Room: /open/badman/room/r10

#include </open/open.h>

inherit ROOM;

int blade = 5;
int sword = 5;
string look_shelf();

void create ()
{
  set ("short", "兵器库");
  set ("long", @LONG
这里是恶人谷的兵器库，房间四周的架子(shelf)上放满了各式
各样的兵器，多的足够让一百名山贼倾巢而出。虽然架子上的武器
都不是什么稀世兵器，但都还算实用，或许你可以找一样武器来试
试看。你看到墙上贴了一张布告(note)。

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "要申请武器请向值班人员报告所需武器种类( report 武器 )。
",
  "shelf" : (: look_shelf :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"b6",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/wguard" : 2,
]));

  setup();
}

void init()
{
	add_action("do_report", "report");
	add_action("do_take", "take");
}

int valid_leave(object who, string dir)
{
	if( dir=="up" && present("guard", this_object()) )
		return notify_fail("守卫挡在你面前说道：这里禁止进入。\n");
	return ::valid_leave(who, dir);
}

string look_shelf()
{
	object who = this_player();

	if( !blade && !sword )
		return "架子上已经没有你可以用的武器了。\n";
	tell_object(who,"你看到架子上有：");
	if( blade )
		tell_object(who,chinese_number(blade)+"把钢刀\n");
	if( sword )
		tell_object(who,"\t\t"+chinese_number(sword)+"把短剑\n");
	return "";
}

int do_report(string weapon)
{
	object who, guard;
	who = this_player();
	guard = present("guard", this_object());

	if( !guard )
	return notify_fail("根本就没人你还报告啥啊？直接拿(take)啦！\n");
	if( !weapon || (weapon!="钢刀" && weapon!="短剑") )
		return notify_fail("你要申请哪一种武器？\n");
	if( who->query("family/family_name")!="恶人谷" )
		return notify_fail("守卫说道：你不是恶人谷的人，少来烦我。\n");
	if( who->query_temp("get_weapon") ) {
		return notify_fail("守卫看了看你说：小子，你不是拿过了吗？\n");
	}
	if( weapon=="钢刀" ) {
		if( !blade )
			return notify_fail("守卫看了看架子后说道：已经没有钢刀了。\n");
		else {
			message_vision("守卫拿了一把钢刀交给$N。\n", who);
			new(BAD_OBJ"steel_blade")->move(who);
			blade--;
		}
	}
	if( weapon=="短剑" ) {
		if( !sword )
			return notify_fail("守卫看了看架子后说道：已经没有短剑了。\n");
		else {
			message_vision("守卫拿了一把短剑交给$N。\n", who);
			new(BAD_OBJ"short_sword")->move(who);
			sword--;
		}
	}
	who->set_temp("get_weapon", 1);
	return 1;
}

int do_take(string weapon)
{
	object who, guard;
	who = this_player();
	guard = present("guard", this_object());

	if( !weapon || (weapon!="钢刀" && weapon!="短剑") )
		return notify_fail("你要拿什么？\n");
	if( guard )
		return notify_fail("守卫对你怒喝道：你要干什么！看不懂墙上的布告啊？\n");
	if( weapon=="钢刀" ) {
		if( !blade )
			return notify_fail("钢刀早就没啦！还轮的到你拿？\n");
		else {
			message_vision("$N从架子上拿了一把钢刀。\n", who);
			new(BAD_OBJ"steel_blade")->move(who);
			blade--;
		}
	}
	if( weapon=="短剑" ) {
		if( !sword )
			return notify_fail("短剑早就没啦！还轮的到你拿？\n");
		else {
			message_vision("$N从架子上拿了一把短剑。\n", who);
			new(BAD_OBJ"short_sword")->move(who);
			sword--;
		}
	}
	return 1;
}
