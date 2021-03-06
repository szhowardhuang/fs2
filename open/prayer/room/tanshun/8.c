///u/r/rence/room/tanshun/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",@LONG

        此处是天璇门成员讨论问题的所在, 往南则是天璇门的玄
        关 (open door). 出去大厅后便是天璇门的练武场. 往北
        则是到门主的宝座. 两旁站着门内各高阶干部, 个个表情
        严肃, 专心地听门主指示!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",                     //议事厅
        "south":__DIR__"1-door",                //玄关
        "east":__DIR__"7",              //议事厅
        "west":__DIR__"9",              //议事厅
        ]) );

        set("light_up", 1);
        create_door("south","圣火刻纹木雕门", "north",DOOR_CLOSED);
   setup();
}
