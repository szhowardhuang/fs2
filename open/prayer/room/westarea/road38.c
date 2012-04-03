//open/prayer/room/westarea/road38.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 往东北方可以
	到达圣火教的总坛. 西方则可以到达圣火教支部的"瑶光门", 
	与飘渺四宫的"朱雀宫". 
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road37",		//街道
        "west":__DIR__"road39",		//街道
 
        ]) );
        
        set("no_fight", 0);
    setup();
}
