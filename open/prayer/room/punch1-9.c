//open/prayer/room/punch1-9

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛大听");
  set ("long", @LONG

    在你身旁的花冈墙上，刻着许许多多用行书写的文字，并且井然有序
，头绪分明，上面写的正是圣火教的教规，看来圣火教是一个非常有制度
，教规深严的组织．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-7",		//`大厅
	"south" : "/open/prayer/room/punch1-12",	//`大厅
	"west" : "/open/prayer/room/punch1-10",		//`大厅
]));

  setup();
}
 
