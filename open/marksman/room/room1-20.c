// Room: /u/f/fire/room/room1-20.c
inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", HIY"箭盟聚众"NOR);
  set ("long", @LONG
这里是弓箭聚会的场所，也是弓箭手的公会所在。花岗岩所作成
，富丽辉煌，显得玲珑可人。其上雕刻几个行书写成的大字，更添风
流潇洒。这里似乎可以让成为弓箭手的一员。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/master_b.c" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-19",
]));

  setup();
}
