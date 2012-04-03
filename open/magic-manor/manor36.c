#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "小径");
	set ("long", @LONG
在练武广场东方的一条小径，这条小径看上去似乎不怎么起眼的
走在这条小径上，人气似乎不像在习武广场上那么的热烙，只有冷冷
清清的感觉，小径的前方可以看到一个亭子。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"east"	: __DIR__"manor51",
	"west"	: __DIR__"manor35",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
