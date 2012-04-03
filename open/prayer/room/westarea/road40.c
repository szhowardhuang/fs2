//open/prayer/room/westarea/road40.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 东边是通往飘渺四
	宫之一的"玄武宫". 北边是圣火教的圣火八天门, 与圣火教比较起
	来, 飘渺城的势力似乎明显地小了很多!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"road35",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
