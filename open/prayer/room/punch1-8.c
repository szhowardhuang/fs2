//open/prayer/room/punch1-8

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛大听");
  set ("long", @LONG

    看来前面就是圣火教军师的大厅了，来这里的教徒似乎并不多，可能
只在有传达命令及军师的嫡传弟子才会经过，和副教主比较起来真的是天
让之别...... 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-4",		//`军师
	"south" : "/open/prayer/room/punch1-11",	//`大厅
]));

  setup();
}
 
