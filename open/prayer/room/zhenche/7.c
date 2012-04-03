//u/r/rence/room/zhenche/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",@LONG

        在议事厅的东南角, 有一个总教头正一脸无奈的样子. 想
        必也对督导门生练武不周的事感到很愧咎! 气氛也显得很
        凝重!

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"4",             //议事厅
        "west":__DIR__"8",              //议事厅
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-officer" : 1,         
]));

   setup();
}
