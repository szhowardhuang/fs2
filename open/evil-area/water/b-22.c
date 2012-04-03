inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 扬 居 -- 后 院"NOR);
	set("long",@LONG
在你眼前，有一座木制的马厩，马厩内只养育一匹金黄色的骏马
，全身泛着金黄色的光芒，十分的炯炯有神，仿佛天将神兵一般的气
势让你不敢随意动牠分毫。
LONG);
	set("no_fight",1);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-27",
"south":__DIR__"b-25",
"west":__DIR__"b-21",
]));
	set("objects",([
__DIR__"npc/horse":1,
]));
	setup();
}

 