inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
花香轻飘扑鼻，你忍不住的发出赞叹声，实在很难想像，一个邪
灵将，荼炭生灵后，竟然会在邪灵界管理着这样的一个地方，鸟语花
香，百物安宁，简直不像是一个邪灵使所会做的一件事情，难不成，
情中有什么隐情迫使着她吗？
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"a-08",
"west":__DIR__"a-06",
]));
	setup();
}

 