#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死灵幽谷"NOR);
set("long",@LONG
抬头一望, 可以依稀看到你所跳下来的细缝露出了些
微的亮光, 地上长满了野草, 使得你跳下细缝时并没有受
到多大的冲击力。
LONG);
set("exits",([
"down":__DIR__"g-h03",
]));
set("no_transmit",1);
setup();
}

