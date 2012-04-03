// Room: /open/su/room/jail/jail_in.c

inherit ROOM;
#include <room.h>

#include <ansi.h>

void create()
{
        set("short", "监牢入口");
        set("long", @LONG
昏暗的光线，以及恶心的臭味，都使你忍不住想快点离开这里。除
非你是想来劫狱，否则还是快点离开吧。一座生锈的厚重铁门(door)矗
立在这，门前站着两个身材精练的卫士!!想劫狱?!来点会的吧～～
LONG);

        set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/hall/way1",
  "enter" : "/open/hall/jail/jail.c",
]));

         set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/j_guard" : 2,
]));
create_door("enter", HIR"厚重锈气的铁门"NOR, "out", DOOR_CLOSED);
        setup();

}

