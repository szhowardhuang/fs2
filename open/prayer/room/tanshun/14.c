//open/prayer/room/tanshun/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG

        走廊的廊顶是使用上等的西域桧木建造的, 随时都会散发
        出特有的桧木香. 西边是练武场, 顺着走廊则可以到达副
        门主的办公房. 不过副门主好像不欢迎女性..

LONG);

        set("outdoors", "/open/prayer/room");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"12",             //走廊
        "west":__DIR__"15",             //走廊
 
        ]) );
        
  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是无法进入副门主的办公房的 !\n");
        
   return 1;
}

