//open/prayer/room/tangi/tangi1-29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG
此处是明教分部之一的天机门的走廊,走廊上可见到跑堂正在辛劳的四处奔波. 
南边是厨房.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-36",		//厨房
	"north":"/open/prayer/room/tangi/tangi1-24",		//走廊
       
        ]) );
     
  setup();
}
