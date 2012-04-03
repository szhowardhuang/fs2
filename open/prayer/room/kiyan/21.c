//open/prayer/room/kiyan/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	开阳门的练武场, 练武场上的弟子正在练功. 传闻圣火教的武学
	共有三套, 其中之一的先天乾坤功, 威力无俦!!不过确是须要不 
	断的练习!!南边是开阳门与外界往来进出的大门, 你可以打开大
	门(open door).

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"14",		//练武场
	"south":__DIR__"2-door",	//练武场
	"west":__DIR__"22",		//练武场
	"east":__DIR__"20",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));

        set("light_up", 1);
        create_door("south","圣火刻纹精钢大门", "north",DOOR_CLOSED);     
  setup();
}

