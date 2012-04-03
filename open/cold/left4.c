// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
set("short","观心楼");
	set("long", @LONG
这里是寒谷中最为清雅的一处地方，名曰「观心楼”，由于
修习仙法必须心无杂念，然而，一般人总是摆脱不了红尘俗事的
羁伴，所以掌门总是会叫一些弟子来此处修心养性，让自己的心
平静下来。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"northeast":COLD_ROOM"left2",
]));
	set("objects",([
	COLD_NPC"trainee4":1,
	]));
	setup();
	replace_program(ROOM);
}
