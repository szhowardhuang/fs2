inherit ROOM;
#include <ansi.h>
void create ()
{
    set ("short", "狂想空间建言处");
	set( "build", 60 );
    set ("long", @LONG
这里就是让狂想的玩家用来发表对于狂想空间的建议的地方::
除了:帮派(clan)、门派(class)、技能(skill)请到适合的地
方之外,你对狂想的制度,人事,主架构有何建议的地方都可以
在这里发表。

	狂想空间巫师工作分配表 (help area)

LONG);

    set("valid_startroom", 1);
    set("no_transmit", 1);
    set("exits", ([ /* sizeof() == 2 */
//	"south" : "/open/wiz/meqroom.c",
	"north" : "/open/common/room/inn",
      ]));
    set("light_up", 1);
    set("no_kill", 1);
    set("no_chome", 1);
    set("no_fight", 1);

    setup();
    //call_other("/obj/board/fsstr_b","????");
}
