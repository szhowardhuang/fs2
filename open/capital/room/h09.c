// Room: /open/capital/room/h09.c

#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
  set ("long", @LONG
这里已接近胡同底了, 不过人潮似乎还多了一点, 原因就是干通天
在这开了一家商行和钱庄, 买进卖出的, 人潮与货物川流不息, 为芝麻
胡同增添另一种生气。南边有家钱庄，北边则是商店。

LONG);

  set("objects", ([ /* sizeof() == 2 */
   CAPITAL_NPC"duan5" : 1,
   CAPITAL_NPC"duan12" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cshop.c",
  "west" : __DIR__"r25.c",
  "south" : __DIR__"cbank.c",
  "east" : __DIR__"h10",
]));

  setup();
}
