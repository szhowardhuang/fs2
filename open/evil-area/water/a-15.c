inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
轻飘而来的花香扑鼻，你忍不住的陶醉其中，回想着人间各地，
似乎也只有烟雨江南才能与此地相抗衡，风光景色，优美鸟啼，细雨
轻飘，如诗如画，你几乎已经忘了自己身处恐怖的邪灵界了。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-16",
"north":__DIR__"a-14",
]));
	setup();
}

 