#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR);
        set("long",@LONG
阵阵的腥臭味不断的扑鼻而来, 你忍不住的捏住
了鼻子, 地上偶尔会传来阵阵的摇晃, 感觉很不舒服
, 南边似乎有生物在那叫喊着, 或许你应该往那边看
看..
LONG);
        set("exits",([
        "south":__DIR__"g-r04",
        "north":__DIR__"g-r02",
        ]));
        set("no_transmit",1);
        setup();
}
