//open/prayer/room/1elder1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "传功长老房");
  set ("long", @LONG

	    圣火教总舵三位护教长老之一的传功长老所
	专属的办公处．传功长正在那里抄写武学的心法
	...西边是往走廊的方向．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/gonfu-elder" : 1,		//传功长老
]));
  set("exits", ([ /* sizeof() ==  1*/
	"west" : "/open/prayer/room/1elder3",		//`长老房
]));
 set("light_up", 1);
  set("valid_startroom", 2);

  setup();
}
