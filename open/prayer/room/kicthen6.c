//open/prayer/room/kitchen6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

	    这里就是圣火教的伙房了，四周传来阵阵
	的香味，使你不自觉的肚子饿了起来，真想进
	到伙房里面大快硕耳一下．

LONG);
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-19",		//`走廊
	"east" : "/open/prayer/room/kicthen7",		//`厨房
	"south" : "/open/prayer/room/kicthen3",		//`厨房
	"west" : "/open/prayer/room/kicthen5",		//`厨房
]));
   set("light_up", 1);

  setup();
}
 
