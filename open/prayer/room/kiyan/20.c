//open/prayer/room/kiyan/20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	开阳门的练武场, 练武场上的弟子们正在练功,传闻圣火教的武学共
	有三套,其中之二的浑天宝鉴心法, 是女娲娘娘所遗留下来的武学!!
	修习之后不但能增强本身的内力!!更能发挥许多另人叹为观止的惊人
	美技!!

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"13",		
        "west":__DIR__"21",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
