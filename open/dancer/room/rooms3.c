// Room: /open/dancer/room/rooms3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIC"练舞场"NOR);
  set ("long", @LONG
这里是夜梦小筑的练舞(武)场，在此你可以看到许多弟子们生涩
的舞姿，当然也可以看到先进弟子们曼妙优雅的舞姿，所有的夜梦弟
子们都是在此练习技能的，因此这里也成了众弟子研究讨论之所。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : "/open/dancer/room/roomse1.c",
  "west" : "/open/dancer/room/roomsw1.c",
  "north" : "/open/dancer/room/rooms2.c",
  "south" : "/open/dancer/room/rooms4.c",

]));
 set("objects", ([ /* sizeof() == 1 */
 "/open/dancer/npc/rgirl.c" : 2,
]));
  set("light_up", 1);
  setup();
}
