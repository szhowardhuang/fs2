//open/prayer/room/kitchen5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

	    你看到许许多多的瓶瓶罐罐，这些瓶瓶罐
	罐内，所装的正是材．米．油．盐．酱．醋．
	茶一类的东西．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/kicthen2",		//`厨房
	"east" : "/open/prayer/room/kicthen6",		//`厨房
]));
   set("light_up", 1);

  setup();
}
 
