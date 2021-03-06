inherit ROOM;
#include <ansi.h>
int do_check();
int do_dest();

void create ()
{
	set("short",HIG"琰 扬 居 -- 后 院"NOR);
	set("long",@LONG
地上放着一块垫高的木头与劈材用的斧头，如果你想劈材的话，
必须先拿起(hold)斧头，然后再大力的砍(cut)下去。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-20",
"east":__DIR__"b-24",
]));
	setup();
}

void init()
{
add_action("do_hold","hold");
add_action("do_cut","cut");
}

int do_hold()
{
object me;

	me = this_player();

	if( me->query_temp("evil/water/cut") )
		return notify_fail("你已经高举斧头了。\n");

	message_vision("$N高举着斧头。\n",me);
	if( random(50) > (int)me->query("str") )
	{
		message_vision("$N由于力量不够的样子，手中的斧头不断的在晃动～\n",me);
		me->set_temp("evil/water/cut",1);
	}
	else
	{
		message_vision("$N拿稳了斧头，握在手中，十分的稳健。\n",me);
		me->set_temp("evil/water/cut",2);
	}
return 1;
}

int do_cut()
{
object me,ob;
int i;

	me = this_player();

	if( !me->query_temp("evil/water/cut") )
		return 0;

	if( !present("burned-torch",environment(me)) )
	{
		me->delete_temp("evil/water/cut");
		return notify_fail("你大力挥舞着手中的斧头，可是...地上并没有木材可让你砍的..\n");
	}

	message_vision("$N大力挥舞着手中的斧头～\n",me);
	if( (int)me->query_temp("evil/water/cut") > 1 )
	{
		if( random(100) < 90 )
			me->set_temp("evil/water/cut_item",2);
		else
			me->set_temp("evil/water/cut_item",1);
	}
	else
	{
		if( random(100) < 10 )
			me->set_temp("evil/water/cut_item",2);
		else
			me->set_temp("evil/water/cut_item",1);
	}
	me->delete_temp("evil/water/cut");
	do_check();
return 1;
}

int do_check()
{
object obj,me;

	me = this_player();

	if( !me->query_temp("evil/water/cut_item") )
		return 0;
	if( (int)me->query_temp("evil/water/cut_item") > 1 )
	{
		message_vision("结果$N精准的将木材劈成两半。\n",me);
		obj = new(__DIR__"obj/good_torch");
	}
	else
	{
		message_vision("结果$N不小心打偏了中心点，木材变的半大不小的。\n",me);
		obj = new(__DIR__"obj/bad_torch");
	}
	obj->move(environment(me));
	me->delete_temp("evil/water/cut_item");
	do_dest();
return 1;
}

int do_dest()
{
object me,obj;

	me = this_player();
	obj = present("burned-torch",environment(me));

	if( present("burned-torch",environment(me)) )
		destruct(obj);
return 1;
}
