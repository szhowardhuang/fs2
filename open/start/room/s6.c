// Room: /open/start/room/s6.c

#include <../start.h>

inherit ROOM;

void create ()
{
  set ("short", "牛舍");
  set ("long", @LONG
牛一直是人类最忠实的伙伴，更是农夫们的好帮手，
吃苦耐劳的天性，使的农夫们能够顺利的耕种，也因此，
牛对于农夫们的重要性更甚于其他。
    这村子的家畜都是采集中饲养的方式，由专人照顾，
以免宵小的肆虐。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/start/room/s7",
  "north" : "/open/start/room/s4",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/b_guard" : 1,
  "/open/start/npc/y_buffalo" : 2,
]));

  setup();
}
