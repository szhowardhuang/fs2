#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "交叉路口");
  set ("long", @LONG

   穿过山道之后，你来到了一个广大的山谷之中。前方似乎有一个建筑物。
   东方传来武器的碰撞声，且杀声连天，看来有人在那里交手，
   西方传来阵阵的花香，那里似乎种了不少植物。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr1.c",
      "east" : __DIR__"outr6.c",
     "north" : __DIR__"doorm.c",
      "back" : __DIR__"firstrm.c",
]));
  setup();
}