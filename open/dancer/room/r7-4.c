// Room: /open/dancer/room/r7-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","小路");
  set ("long", @LONG
你正走在山野小路之中，向西走可以进入村庄，东边和北边则都是
草原，南方是一片茂盛的树林。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/dancer/room/r6-4.c",
  "east" : "/open/dancer/room/r7-5.c",
  "west" : "/open/dancer/room/r7-3.c",

]));

  set("light_up", 1);

  setup();
}
