inherit ROOM;
#include <ansi.h>
#include <tree.msg>

void create()
{
	set("short",HIG"琰 扬 居 -- "NOR+YEL"大 松 树"NOR);
	set("long",@LONG
你突然被这里的某样东西所吸引，不是美丽的风景，也不是奇特
的邪灵，而是一种会散发出奇特味道的树脂，一只阙雀正在一旁拉扯
着那快要断裂的树枝，拉着拉着，一股奇特的味道让阙雀忍不住放弃
了这根树枝飞离开了这棵大松树，看来你只要在出点力气就可以将木
枝给拔(uproot)了下来。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-40",
]));
	setup();
}

void init()
{
add_action("do_uproot","uproot");
}

int do_uproot()
{
object me,obj;
int str;

	me = this_player();
	str = (int)me->query("str");

	if( me->query_temp("evil/water/uproot") )
		return notify_fail("树枝已经被拔走了，只留下一个断裂的树干。\n");
	message_vision("$N一使力，整个树枝都被拔了下来。\n",me);
	obj = new(__DIR__"obj/keep_bee");
	obj->move(me);
	tell_object(me,"你拿到了一个"+obj->name(1)+"。\n");
	me->set_temp("evil/water/uproot",1);
	if( str > random(50) )
	{
		message_vision("$N拔的太大力，结果一不小心就掉了下去...\n",me);
		tell_object(me,HIY"你心想：完了...:~...\n"NOR);
		me->move("/open/evil-area/water/b-20");
		me->receive_wound("gin",200);
		me->receive_wound("kee",300);
		me->receive_wound("sen",100);
		COMBAT_D->report_status(me,1);
		return 1;
	}
return 1;
}

