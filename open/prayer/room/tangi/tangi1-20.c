//open/prayer/room/tangi/tangi1-20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"天机门的走廊，走廊上可见到跑门正在辛劳的四处奔波，走廊的廊顶是使用上等的
西域桧木建造的，随时都会散发出特有的桧木香．副总教头正在督促着门人练武.\n");

        set("outdoors", "/u/r/rence");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "south":"/open/prayer/room/tangi/tangi1-25",		//练武场
	"east":"/open/prayer/room/tangi/tangi1-21",		//走廊
        "west":"/open/prayer/room/tangi/tangi1-19",		//走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		//副总教头
   		
]));
                
  setup();
}
