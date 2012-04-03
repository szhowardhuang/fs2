//open/prayer/room/train1-2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    这里有一个门，里面正是圣火教的马房，
	里有许许多多的马匹，南方是通往传功房及戒
	律厅的路．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-5",		//`走廊
	"enter" : "/open/prayer/room/horse6",		//`马房
	"west" : "/open/prayer/room/train1-1",		//`练武场
]));

  setup();
}
 
