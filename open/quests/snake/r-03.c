inherit ROOM;
#include <way.c>

void create()
{
	set("short","蛇寨");
	set("long",@LONG
在你身旁伫立着一个蛇的石雕像，雕像上面似乎有刻着一些文字
，但似乎不是你所能理解的文字，东西两旁摆放着许多的桌椅，看来
这里似乎是大厅的休息室。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier":2,
]));
	set("exits",([
"west":__DIR__"r-09",
"east":__DIR__"r-08",
"north":__DIR__"r-04",
"south":__DIR__"r-02",
]));
	setup();
}
