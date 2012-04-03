//open/prayer/room/youkoun/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副门主书房");
        set("long",@LONG

        这里是瑶光门副门主的书房, 有个女弟子正在打扫房间.
        书架上是一排排的书, 想来副门主也是个饱读诗书之人.
        往西一直走出去就是练武场.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"6",         //副门主室
        "southwest":__DIR__"8",         //副门主室
        "west":__DIR__"7",              
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
