//open/prayer/room/tanchun/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	天权门的练武场, 练武场上的弟子正在接受总教头的指导勤练外家
	功夫. 传闻圣火教的武学三绝之一的先天乾坤功, 威力无俦!!不过
	需要不断的练习自身的外家拳脚!!   

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"14",		//走廊
	"south":__DIR__"19",		//练武场
	"west":__DIR__"16",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
