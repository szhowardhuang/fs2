//open/prayer/room/youkoun/11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的西北角落, 有位师姊正在个别指导师妹的动作
        . 瞧她说得很认真的样子, 可惜师妹还是一知半解..从这
        往西是通往总管房的走廊.

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"10",             
        "south":__DIR__"18",            //练武场
        "west":__DIR__"13",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
