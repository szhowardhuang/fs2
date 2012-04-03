inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
对于你正东方有一个建筑物正漂浮于水面上，吸引了你的视线，
你边走边望向湖泊上的建筑物，一不小心你就撞到了正旁行在地上的
邪兽～尽管你不断的道歉，邪兽似乎完全听不懂你在说什么，顾自的
继续爬行，面对这种窘况，你也只好笑了笑，继续的走着。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob01":1,
__DIR__"npc/mob02":1,
__DIR__"npc/mob03":1,
]));
	set("exits",([
"north":__DIR__"a-21",
"south":__DIR__"a-19",
]));
	setup();
}

 