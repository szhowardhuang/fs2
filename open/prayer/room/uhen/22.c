//open/prayer/room/uhen/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        你看到练武场上的二名弟子正在练武场上跑来跑去.  
        脚上似乎还绑着相当沉重的铅块来训练脚力. 看来门 
        主对于腿力相当的重视.
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"15",		
        "east":__DIR__"21",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,		//弟子
        "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
