#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "聚灵阶");
	set ("long", @LONG
登上聚灵阶，可以感觉些微的灵气缓缓朝你飘过来，再往前走就
可以抵达江湖上鲜为人知的聚灵山庄了。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor49",
	"out"	: __DIR__"town/town44",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
