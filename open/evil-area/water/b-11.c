inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 扬 居"NOR);
	set("long",@LONG
这是一大厅通往后厢房的一个转角处，往东通往大厅，往南通往
后厢房。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"b-09",
"south":__DIR__"b-16",
]));
	setup();
}

 