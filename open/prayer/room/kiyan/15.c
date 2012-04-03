//open/prayer/room/kiyan/15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	开阳门的练武场, 练武场上的弟子正在练功. 传闻圣火教的武学
	共有三套, 其中之一的先天乾坤功, 威力无俦!!可是正是因为如 
	此, 所以根基绝对不能够太差, 以免因此而造成自身的危害!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
 	"east":__DIR__"14",		
	"south":__DIR__"22",		//练武场
	"west":__DIR__"17",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
 int valid_leave(object me, string dir)
  {
    if(dir=="west"&&me->query("gender")=="男性")
        return notify_fail("男人是无法进入总管的办公房的 ?\n");
        
   return 1;
}
