//open/prayer/room/tanshun/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的西方, 有两个弟子正在讨论最近圣火教内发生
        的事情. 你仔细一听, 原来是有个武功高强的师兄暂时隐
        居去了. 瞧他们讲得口沫横飞, 也不晓得是真是假..

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",            //练武场
        "south":__DIR__"27",            //练武场
        "east":__DIR__"20",             //练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee3" : 1,              //弟子
                
]));
     
  setup();
}
