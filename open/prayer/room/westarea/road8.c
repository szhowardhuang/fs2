//open/prayer/room/westarea/road8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 东边是圣火八天
	门之一的"天枢门", 门主葛辉乃是西域人士, 为教派付出心力颇
	多, 故成为教主最倚重的人物!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road4",		//街道
	"south":__DIR__"road11",	//街道
	
     "east":"/open/prayer/room/tanshu/2-door",       //街道
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
