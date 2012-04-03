//open/prayer/room/kiyan/17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

	开阳门总管的书房, 这里是总管处理门务的地方. 总管是门主以下
	与副门主同一职等的干部..所以你可以发现房内有许多的保镳在护
	卫着总管大人. 北边是往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"16",		//总管房
        "south":__DIR__"18",		//总管房
        "east":__DIR__"15",		//总管房
        "west":__DIR__"19",		//总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon2" : 2,		//保镳
   		
]));
     
  setup();
}
