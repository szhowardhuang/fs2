
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "血魔堡二楼");
  set ("long", @LONG
此地为血魔堡二楼，由于越来越接近血魔主城，故地上残骸
也比一楼多出许多，可见当年大战之惨状。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : "/open/gsword/room1/blood/room2/r3.c",
  "south" : "/open/gsword/room1/blood/room2/r9.c",
  "east" : "/open/gsword/room1/blood/room2/r3.c",
  "west" : "/open/gsword/room1/blood/room2/r11.c",
  "up" : "/open/gsword/room1/blood/room3/r1.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}
