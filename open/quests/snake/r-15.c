inherit ROOM;
#include <way.c>

void create()
{
	set("short","蛇寨 二层");
	set("long",@LONG
石制的蛇寨显得十分的坚固，你正位于蛇寨前栋的东南角，东西
两旁，各放置着一张木桌与许多的椅子，看来这层是供蛇寨的守卫休
息的地方。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier":1,
]));
	set("exits",([
"west":__DIR__"r-14",
"east":__DIR__"r-16",
"down":__DIR__"r-06",
]));
	setup();
}
