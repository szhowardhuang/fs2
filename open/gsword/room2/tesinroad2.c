//tesinroad
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"铁心居"NOR);
        set("long", @LONG
走出树林.顿时海阔天空.你见到一个完全不属于中原武林的景象...
你正前方有一个类似房屋的建筑.路旁亦发现一颗极大的花岗石..上面
写着‘铁心居’。
LONG );
        set("exits", ([ /* sizeof() == 3 */
 "enter":"/open/gsword/room2/tesinroom.c",
 "south":"/open/gsword/room2/tesinroad1.c",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}




