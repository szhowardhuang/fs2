//open/prayer/room/tangi/tangi1-11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",
"此处是天机门成员讨论问题的所在，也是门主发落门生与命令的地方． 厅的大小约有
百尺见方，四周陈设金壁辉煌，门徒行走络绎不绝，可见得天机门的门徒众多，不愧\
是圣火八天之中最大的一个支门．\n");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-14",		//议事厅
        "east":"/open/prayer/room/tangi/tangi1-12",		//议事厅
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		//副总管
]));

   setup();
}
