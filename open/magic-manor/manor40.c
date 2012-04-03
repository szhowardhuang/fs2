#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "穿堂");
	set ("long", @LONG
从大门走进这个穿堂里，光线充足，穿堂东西方个有一条走道，
是来访的客人休息的地方，一直往前方走去则有一条通道是可以进入
山庄里面的通道。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor39",
	"south"	: __DIR__"manor49",
	"east"	: __DIR__"manor67",
	"west"	: __DIR__"manor66",
	]));

	set("light_up", 1);

	setup();
}
