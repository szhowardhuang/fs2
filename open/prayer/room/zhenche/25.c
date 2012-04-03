//open/prayer/room/zhenche/25.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的东南角, 有两个弟子正在聊天. 你走进一听,
        原来是在讲他们门主的风流韵事! 瞧他们讲得津津有味
        , 难到阵势门主真是个风流之辈吗?

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"19",            
        "west":__DIR__"26",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
