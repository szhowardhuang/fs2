#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
          set("short","紫云宝殿");
        set("valid_startroom", 1);
set ("long", @LONG
这里是雪苍派的圣地‘紫云宝殿’，宝殿里装饰着 无数的珍宝 ,
显得华丽非凡，是雪苍派弟子聚会时，或有贵客来临时候的一个重要
场所。
LONG);
set("exits",([
		"south":__DIR__"room5_out",
		"north":__DIR__"room6",
		"east":__DIR__"room10",
		"west":__DIR__"room18",
        ]) );
	set("light_up",1);
	set("objects",([
	"/open/snow/npc/sing-chens" : 1,
	]));
        setup();
}
void init()
{
	object me = this_player();
	if( wizardp(me) && me->query("id") != "fund" ) me->move("/open/wiz/jobroom");
}
int valid_leave( object me , string dir )
{
	object ob;
	if( dir != "north" ) return 1;
	if( ( ob = present( "sing chens",this_object() ) ) ) {
		message_vision("$N说道：这个地方不能随便进入。\n",ob);
		return 0;
	}
	return 1;
}
