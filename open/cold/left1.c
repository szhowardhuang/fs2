// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","西侧小路");
	set("long", @LONG
这里是由宝珍神宫正门通往西侧神殿的必经小道，在小道旁种满了
青蔓藤草，生得十分茂盛，此外，北面是神宫侧面的墙壁，虽然序并没
有什么特殊的修饰，却隐隐的散发出一股寒气，让人看了不禁打起一阵
寒颤。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"east":COLD_ROOM"home1",
	"west":COLD_ROOM"left2",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
