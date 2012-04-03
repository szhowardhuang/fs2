// Room: /open/dancer/room/r8-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","民房");
  set ("long", @LONG
这里是一间普通的民房，你可以看到屋内的摆设极为简陋，由此
可知镜月岛人民的生活并不富裕。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r8-3.c",

]));

  set("light_up", 1);

  setup();
}
