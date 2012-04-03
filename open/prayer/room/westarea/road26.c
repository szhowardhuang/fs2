//open/prayer/room/rwestarea/road26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华, 西边是圣火
	教麾下的分部之一--"玉衡门". 玉衡门主是位西域土生土长
	的美人, 身材标致, 对于乾坤大挪移的造诣已经达到顶峰, 
	所以轻功更是一绝......
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road23",		//街道
	"south":__DIR__"road31",		//街道
      "west":"/open/prayer/room/uhen/2-door",         //大门
 
        ]) );
        setup();
}
