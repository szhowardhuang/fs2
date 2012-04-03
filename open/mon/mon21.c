inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "长白山腰");
  set ("long", @LONG
历尽长途拔涉，你已经来到了长白山的半山腰了，环看远方，你
已经有种登高的感觉，慢慢的你如深陷于云海之中，渐渐看不清远方
的山，云气慢慢的向你聚集而来，让你想快快开这里。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fox.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"mon20",
  "north" : __DIR__"mon22",
]));

  setup();
}
