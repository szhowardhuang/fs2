#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死灵幽谷"HIW"□白洞□"NOR);
set("long",@LONG
你下定决心的来到了死灵骨魔的领地, 四周的
岩壁都不见了, 取而代之的是光亮的空间, 周围亮
光四射, 景色仿佛一片白昼, 无限的向四周延伸, 
一片白亮....
LONG);
set("exits",([
"north":__DIR__"g-h12",
"south":__DIR__"g-h12",
"east":__DIR__"g-h12",
"west":__DIR__"g-h12",
]));
set("no_transmit",1);
setup();
}
