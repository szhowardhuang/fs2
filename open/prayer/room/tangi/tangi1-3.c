//open/prayer/room/tangi/tangi1-3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天机门大厅");
        set("long",
"整座大厅的装潢除了充满庄严之外，特别还有一股文人雅士的气息．壁上四处可见
大型的泼墨画，与门主的品味互相融合．厅上所站立的是天机门的左护法．后面是一
道铁门，但是不知道它通往何处?\n");
        set("exits", ([ /* sizeof() == 2 */
        "east":"/open/prayer/room/tangi/tangi1",		//堂主
        "west":"/open/prayer/room/garden4",      
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/left" : 1,		//左护法
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="west"&&present("hu-fa left",environment(me)))
return notify_fail("左护法厉声喝道:没有门主的令牌,休想走进一步!\n");
        return ::valid_leave(me,dir);
}
