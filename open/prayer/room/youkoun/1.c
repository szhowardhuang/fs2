//open/prayer/room/youkoun/1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","瑶光门大厅");
        set("long",@LONG

        在大厅的东方站着一位右护法, 专职保护门主的工作. 往
        东则是练功房. 如果你是圣火教徒, 可以随时进去里面练
        习.

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"4",         //大厅
        "west":__DIR__"2",              //门主
        "east":__DIR__"28",
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/right7" : 1,          //右护法
]));
  setup();
}

int valid_leave(object me, string dir)
  {
  if(dir=="east" && me->query("class") != "prayer")
        return notify_fail("不是教徒是不能进入的 !\n");
        
        return ::valid_leave(me,dir);
}

