//open/prayer/room/1elder5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "传功长老房");
  set ("long", @LONG

	    这里又有一位弟子，正一股脑的坐在地上
	发呆，不知是练武遇到瓶颈，还是正在打混摸
	鱼，看来是在等传功长老的样子．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/1elder6",		//`长老房
	"east" : "/open/prayer/room/1elder2",		//`长老房
]));
 set("light_up", 1);

  setup();
}
 
