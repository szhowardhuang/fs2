//open/prayer/room/uhen/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副门主房");
        set("long",@LONG

	玉衡门副门主的办公房.桌上摆满了一些文件.你看到一个弟子
        正在整理文件. 大概是整理完后要交给副门主过目的吧.□
LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"10",		//副门主室
	"southwest":__DIR__"12",		//副门主室
	"west":__DIR__"11",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
