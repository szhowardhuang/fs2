//open/prayer/room/uhen/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        玉衡门的练武场, 练武场上的弟子正在勤练基本的扑击格斗之技
        以奠定日后学习圣火教高深武学--先天乾坤功--的基础. 只见各 
        弟子们正努力的练习着. □
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
           "north":__DIR__"14",		//练武场
	"south":__DIR__"2-door",		//练武场
	"west":__DIR__"22",		//练武场
	"east":__DIR__"20",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee2" : 1,		//弟子
        "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));
        create_door("south","圣火刻纹精钢大门", "north",DOOR_CLOSED);     
     
  setup();
}
