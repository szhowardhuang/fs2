//open/prayer/room/zhenche/26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        进入了阵势门, 眼前突然壑然开朗, 原来是一大片的练
        武场! 练武场上的弟子一个个都在磨练自己的体能, 一
        心希望能够早一天具备修习先天乾坤功的资格!!

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"20",            //练武场
        "south":__DIR__"2-door",        //练武场
        "west":__DIR__"27",             //练武场
        "east":__DIR__"25",             //练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee2" : 1,                //弟子
        "/open/prayer/npc/trainee1" : 1,                //弟子
                
]));
        create_door("south","圣火刻纹精钢大门", "north",DOOR_CLOSED);     
     
  setup();
}
