//open/prayer/zhenche/1-door.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玄关");
        set("long",@LONG

        这里是阵势门的玄关. 往里面 (open door)走则是阵势门
        的议事厅. 外面则是阵势门的练武场, 练武场上到处都是
        习武强身的弟子.

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"8",             //议事厅
        "south":__DIR__"16",            //练武场
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 2,          //值班弟子
                
]));
        set("no_fight", 0);
        set("light_up", 1);
        create_door("north","圣火刻纹木雕门", "south",DOOR_CLOSED);
  setup();
}
