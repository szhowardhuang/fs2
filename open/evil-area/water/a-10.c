inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
步行于湖泊旁，你有一种说不出来的舒适感。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-11",
"north":__DIR__"a-09",
]));
	setup();
}

 