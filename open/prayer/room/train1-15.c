//open/prayer/room/train1-15

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    前面这个入口，便是圣火戒律厅的门口，
	门的里面传来阵阵的哀号声，难到又发生弟子
	犯错的事情了吗．

LONG);
  set("exits", ([ /* sizeof() == 2 */
	"enter" : "/open/prayer/room/3elder6",		//`长老房
	"north" : "/open/prayer/room/train1-10",		//`走廊
]));

  setup();
}
 
