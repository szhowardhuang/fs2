//open/prayer/room/tanchun/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

	天权门总管的书房, 这里是总管处理门务的地方. 总管是门主以
	下与副门主同一职等的干部..专门负责门内事务的处理. 西边是
	往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"28",	//总管房
        "west":__DIR__"23",		//总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,		//保镳
   		
]));
     
  setup();
}
