// Room: /open/start/room/f7.c

#include <../start.h>

inherit ROOM;

void create ()
{
  set ("short", "稻田");
  set ("long", @LONG
你看到一片绿油油的稻田，空气中充满着稻草的气味，
四处树立的稻草人与辛勤工作的农夫们，构成了一幅标准的
农村景象，往北望去可以看到凌云村。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/sparrow" : 1,
  "/open/start/obj/bogle" : 1,
]));

  set("outdoors", "/open/start");

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/start/room/f12",
  "west" : "/open/start/room/f6",
  "north" : "/open/start/room/f2",
  "east" : "/open/start/room/f8",
]));

  setup();
}
