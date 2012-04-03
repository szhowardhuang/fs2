// Room: /u/l/lotus/girl/r6.c
#include <room.h>

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "紫色的房间");
  set ("long", @LONG
一张收拾过的大床, 淡紫色的幛幕, 垂着流苏, 茶几上有一大瓶
盛放天堂鸟, 整个房间给人一种热情如火, 透不过气来的感觉.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : CENTER_ROOM"w3.c",
]));
  set("light_up", 1);

  create_door("north", "雕花木门", "south", DOOR_CLOSED);
  setup();
}
