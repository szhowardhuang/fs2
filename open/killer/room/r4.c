#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","兵器库");
  set ("long", @LONG
这里是黑牙联平时储存兵器的地方，在这里可以看到不少的兵器
但是大多是暗器，只有黑牙联的弟子可以在这里领取兵器，但是必须
先向掌理兵器的兵器使报备(report)，想知道有什么兵器就用(list)。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"west":__DIR__"r3",
]));

  set("objects",([
	"/open/snow/npc/manager":1,
	]));

  setup();
}
void init()
{ 
   add_action("do_search","search");
}
int do_search()
{
   object me;
   me = this_player();
   tell_room(me,""+me->query("name")+"找到了机关，发现了一条出路。\n");
    set("exits", ([
	"west":__DIR__"r3",
	"south":__DIR__"r5",
]));
   return 1;
}
