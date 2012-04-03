#include <room.h>
inherit ROOM;
void create()
{
        set("short","总管的书房");
        set("long",@LONG
这里就是总管书房的最内部了! 银针门的总管正在这里办公，看
他愁眉不展的样子，不知道是在苦思开源节流的方法，还是如何收回扣呢?

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"24",             
        "northeast":__DIR__"22",           
        "north":__DIR__"23",       

        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/doctor/npc/general-manager" : 1,        

]));

  setup();
}


