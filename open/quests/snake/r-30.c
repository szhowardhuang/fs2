inherit ROOM;
#include <way.c>

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG

		～　一片漆黑，什么也看不到 ～

LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/poison_man_3":1,
__DIR__"npc/poison_soldier":2,
]));
	set("exits",([
"west":__DIR__"r-36",
"east":__DIR__"r-31",
"north":__DIR__"r-41",
"south":__DIR__"r-29",
]));
	setup();
}
