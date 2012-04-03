#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","洞穴入口");
  set ("long", @LONG
这里是黑牙联，眼前所见的，正是武林一大杀手组织的的主席
「叶秀杀”，相传此人是一哑吧，但武功之强，非凡人可知，此外
在身旁的是他的弟子，也是武林中响当当的杀手。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"out":__DIR__"black3",
	"east":__DIR__"black5",
     "north" :__DIR__"blackwiz",
]));

  set("objects",([
	"/daemon/class/killer/master_yar":1,
        "/open/main/obj/torch" : 1,
        ]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/killer_b","???");
}
