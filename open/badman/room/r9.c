// Room: /open/badman/room/r9

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "金库内部");
  set ("long", @LONG
还没想到....:b

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r8",
]));
  create_door("north", "铁门", "south", DOOR_LOCKED);

  setup();
}
