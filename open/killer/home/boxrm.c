#include <room.h>
#include "../../open.h"
inherit ROOM;

void create()
{
set("short","装备存放处");
          set("long",@LONG
这里是当年那位医生犯过错后，被监禁后存放装备的地方。
那里就放着一口平常的箱子。或许你可以去看看有什么东西吧。
南方有一个小小的通道，或许那是唯一的出口吧。 
LONG);
        set("exits", ([
"south":__DIR__"outr4.c",
        ]) );
set("objects",([
    "/open/killer/obj/mbox":1,
]));
set("light_up",1);
        setup();
}