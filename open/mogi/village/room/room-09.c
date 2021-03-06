//room:/u/e/eva/village/room/room-09.c    made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","魔界村南村口");
    set("long","
    这里是魔界村的南村口, 魔界村位于魔界的正中央, 由于在村中
自古以来, 有高人在此设下了五行之阵, 凭藉着五行相生相克的力量
, 巧妙的运用使魔物无法进入, 使这里变成魔界中唯一的乐土, 仅有
人类以及低等魔物可以进入.\n\n");
    set ("exits",([
        "north" : __DIR__"room-08",
"south" : "/open/mogi/forest/room61",
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("outdoors",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);  
    setup();
}

int valid_leave(object me,string dir)
{
    if ( me==this_player() && dir=="south" )
        {
        tell_object(me,HIM"你轻轻巧巧的穿过力场, 出了魔界村!\n"NOR);
        }
    return ::valid_leave(me,dir);
}
