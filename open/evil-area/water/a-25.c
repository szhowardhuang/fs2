inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"HIG" 同 心 桥 "NOR);
	set("long",@LONG
在你的正南方，也就是同心桥的终点，有着一个类似人间的建筑
物，看起来虽然有点简陋，却不失风雅，感觉上里面似乎居住着一位
隐士，不过却又不像是隐士所会做的行为，因为门前站立着两个邪灵
，似乎不是普通人可以任意通行。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-24",
"south":__DIR__"a-26",
]));
	setup();
}

 