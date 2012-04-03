//open/prayer/room/tanchun/28.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

	天权门总管的书房, 这里是总管处理门务的地方. 总管是
	由门主挑选出来后, 专门负责门内事务的处理. 北边是往
	走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"24",	//总管房
        "northeast":__DIR__"22",	//总管房
        "north":__DIR__"23",		//总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,		//总管
   		
]));
     
  setup();
}
