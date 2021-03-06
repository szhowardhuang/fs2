#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "八卦迷宫阵");
  set ("long", @LONG
你已经走入八卦迷宫阵，只见四周都是岩石，以及一些困死在此的人的骸骨，在此你已无法辨明方向。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room5h.c",
  "south" : __DIR__"room5b",
  "north" : __DIR__"room5",
  "east" : __DIR__"room5d",
]));
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/snow/npc/ghost" : 1,
]));
  set("valid_startroom", 1);

  setup();
}
