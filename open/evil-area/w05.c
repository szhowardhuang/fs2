inherit ROOM;
#include <ansi.h>
#include <road.msg>

void create ()
{
	set("short",BBLU+YEL"ÕðÐ°µÀ"NOR);
	set("long",
(: print_road_msg :)
);
	set("no_transmit",1);
        set("light_up",-1);
	set("exits",([
"west":__DIR__"e34",
"down":__DIR__"e07",
]));
	setup();
}
