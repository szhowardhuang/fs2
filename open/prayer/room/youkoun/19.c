//open/prayer/room/youkoun/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的东南方, 一个新入门的女弟子正在请教师姊生
        活上的问题. 看来她还不习惯过团体的生活, 而对于门主
        交待的 "一定要痛恨男性" 也是满腹狐疑..

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"16",            
        "west":__DIR__"20",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
