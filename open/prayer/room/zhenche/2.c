//open/prayer/room/zhenche/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","阵势门大厅");
        set("long",@LONG

        西武林中一个势力庞大的组织, 人们统称她为「圣火教”
        , 又称为明教. 此处是明教分部之一的阵势门, 宝座上坐
        着的正是门主, 两旁则分别有左右护法. 阵势门是圣火教
        排行第八的支门.

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"5",             //大厅
        "east":__DIR__"1",              //右护法
        "west":__DIR__"3",              //左护法
 
        ]) );
        set("light_up", 1);
        set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/zhenche" : 1,               //门主
]));
  setup();
}
