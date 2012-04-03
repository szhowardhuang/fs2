//open/prayer/room/westarea/road20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 往东可以到
	达圣火教支门的"天权门"与"开阳门". 北边是钱庄. 破邪洞
	窟的出入口除了山壁外, 听说在总坛内也有另一个出入口!!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
       "north":__DIR__"r1-16.c",	//钱庄  
       "east":__DIR__"road19",		//街道
       "west":__DIR__"road21",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
