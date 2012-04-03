//open/prayer/room/westarea/road10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华, 西边是圣火
	教麾下最大的分部--"天机门". 听说天机门的门主司马锦在
	年少时曾经救过教主的性命呢!!南边与北边各是人来人往的
	街道.
LONG);

       	set("outdoors", "/open/prayer/room");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road5",		//街道
	"south":__DIR__"road15",	//街道
	"west":"/open/prayer/room/tangi/tangi1-34",		//大门
 
        ]) );
        setup();
}
