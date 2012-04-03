//open/prayer/room/tangi/tangi1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天机门大厅");
        set("long",@LONG

	西武林中一个势力庞大的组织, 人们统称她为「圣火教”
	, 又称为明教. 此处是明教分部之一的天机门, 门上所坐
	的是天机门的门主. 天机门是圣火教最大的支门．北边是
	天机门主的书房!!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-1",		//门主的房间
        "south":"/open/prayer/room/tangi/tangi1-12",		//大厅
        "east":"/open/prayer/room/tangi/tangi1-2",		//右护法
        "west":"/open/prayer/room/tangi/tangi1-3",		//左护法
 
        ]) );
        set("light_up", 1);
	set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
	"/open/prayer/npc/tangi" : 1,		//门主
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(me->query("class")!="prayer"&&dir=="north")
	return notify_fail("对不起, 里面是天机门弟子的聚会之地!!\n");
                      
	return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_pass","pass");
}

int do_pass()
{
   object me=this_player();
   me->move("/open/ping/room/road3");
   return 1;
}