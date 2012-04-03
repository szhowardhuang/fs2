//open/prayer/room/punch1-10

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛大听");
  set ("long", @LONG

    你站在象征圣火教的圣火座面前，突然产生一莫名的尊敬，因为这座
圣火座有九尺之高，而且本身是由一块花冈石天然成形的，没有丝毫加工
过，似乎是老天给圣火教的贺礼． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/punch1-2",		//`大厅
	"south" : "/open/prayer/room/punch1-13",	//`大厅
	"west" : "/open/prayer/room/punch1-11",		//`大厅
	"east" : "/open/prayer/room/punch1-9",		//`大厅

]));
  set("light_up", 1);
  setup();
}
 
