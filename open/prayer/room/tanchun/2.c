//open/prayer/room/tanchun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天权门大厅");
        set("long",@LONG

	西武林中一个势力庞大的组织, 人们统称她为「圣火教”, 又称
	为明教. 此处是明教圣火八天门之一的天权门, 厅上所坐的是天
	权门的门主--司徒荣. 天权门是圣火教排行第三的支门．

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"30",		//练功房
        "south":__DIR__"5",		//大厅
        "east":__DIR__"1",		//右护法
        "west":__DIR__"3",		//左护法
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/tanchun" : 1,		//门主
]));
  setup();
}

int valid_leave(object me, string dir)
{
    if(dir=="north" && !me->query("can_study",1) )
        return notify_fail("这是门主私人的练功房!!非请勿入!!\n");
        
   return 1;
}

