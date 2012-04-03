#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "深不见底的绝崖");
  set ("long", @LONG
好不容易走出草阵，确发现此地竟是一处绝崖。崖下
有一阵一阵的狂风杀！杀！杀！的吹着。而且崖面竟有着
云状的雾，你的心霎时凉了一节，这里有这么高吗？这而
的北方似乎有三座会发出异光的桥影…

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/questsfan/obj/corpse.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/ping/questsfan/room6",
  "north" : __DIR__"room1",
]));

  setup();
}
