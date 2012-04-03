// Room: /open/dancer/room/roomse2.c :cgy
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"喷水池"NOR);
        set("long", @LONG
一个别致幽雅的喷水池，这个水池的水源来自于镜月岛底下
的自涌泉，长年有泉水供应，你可以在此装水(fill)，或是在此
饮水，而在这个风景幽雅的地方休息也是一件舒服的事。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"roomse3.c",
  "west" : __DIR__"roomse1.c",
  "north" : __DIR__"roomes2.c",
]));

  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

        set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/obj/pool" : 1,
]));
        setup();
}
