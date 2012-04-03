inherit ITEM;
#include <ansi.h>
#include "../../open.h"
void create()
{
     set_name(HIR "独孤愁的灵柩" NOR,({"box"}));
     set("long","雪苍派第三代掌门独孤愁的灵柩，上面刻着「九转邪云”四个大字。\n");
     set("unit","俱");
     set_weight(1000000);
     set("value",10000);
     setup();
}
void init()
{
	add_action("do_search","search");
	add_action("do_push","push");
	add_action("do_enter","enter");
}
int do_search(string str)
{
	if(str!="box")
		return notify_fail("你在找什么 ?\n");
	tell_object(this_player(),"你发现在灵柩上的四个字，每个字都有一个类似暗门一类的东西。\n");
	return 1;
}
int do_push(string str)
{
	if(str!="九"&&str!="转"&&str!="邪"&&str!="云")
		return notify_fail("你想推那里 ?\n");
	if(str!="邪")
	{
	   message_vision(
		HIY "$N触碰了暗门，被一股强烈的力道反震，$N被弹了出去！\n"+HIR+"$N吐了口鲜血，受了极严重的内伤。\n" NOR,this_player());
	   this_player()->add("kee",-100);
	   this_player()->move(SNOW_ROOM"ducu_room_in");
	   return 1;
	}
	tell_object(this_player(),"灵柩突然「喀”的一声，打了开来，令人大吃一惊，里面并没有独孤愁的遗体，只见一条密道(road)。\n");
	return 1;
}
int do_enter(string str)
{
	if(str!="road")
		return 0;
	tell_object(this_player(),"你慢慢地，一步一步走进密道。\n");
	this_player()->move("/open/snow/room/box_in");
	return 1;
}
