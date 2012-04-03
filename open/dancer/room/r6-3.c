// Room: /open/dancer/room/r6-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","村庄");
  set ("long", @LONG
这里是村庄的北部，你可以向北展开你的旅程，也可以向南回到村
庄内人烟较多之处。由于这座岛上居民不多，因此这里的人口并不多。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/r5-3.c",
  "south" : "/open/dancer/room/r7-3.c",

]));

  set("light_up", 1);

  setup();
}
