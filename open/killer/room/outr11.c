#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "杀手练习场");
  set ("long", @LONG
   这是杀手的练习场，场地非常的宽广场的，周围有许多的树木。
   这似乎是特地为杀手所设计来，用于练习轻功与暗器手法的场地。
   然而，树上也有不少人在进行实战练习。但你却找不出他们的所在。
   只听的到不断传来的杀声与兵器交鸣声。
   广场中，教头正四处的观察着，每个人的练习情形。
   并且随时亲自对招与指导有所缺失的人。。。。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/killer/npc/fu.c" : 1,
  "/open/killer/npc/killer_c.c" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/killer/mon/room/wood1.c",
  "south" : __DIR__"outr9.c",
  "west" : __DIR__"outr10.c",
]));

  setup();
}
