//open/prayer/room/punch1-11

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛大听");
  set ("long", @LONG

    这房间的大理石墙上，刻着一些传神的图案，在这面墙的最上面刻着
一团熊熊的圣火，在圣火的下方站着一个人，而在这一人下面有许多人向
他模拜着，使人有一种君临天下的感觉． 

LONG);

  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-8",		//`大厅
	"south" : "/open/prayer/room/punch1-14",	//`大厅
	"east" : "/open/prayer/room/punch1-10",		//`大厅

]));
  set("light_up", 1);

  setup();
}
 
