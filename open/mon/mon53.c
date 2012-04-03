inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "洞穴通道");
  set ("long", @LONG
一条长长的洞穴通道，两旁的岩壁非常潮溼，渗入了不少的水，
而你的头上不时的滴下了水，溼泞的地上还不时有几只老鼠窜来窜去
的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/red-rat.c" : 3,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"mon52",
  "north" : __DIR__"mon29",
]));

  setup();
}
