inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIR"»€—“µ¿"NOR);
        set("long",@LONG
»€—“µ¿
LONG);
        set("exits",([
"north":__DIR__"d-10",
]));
        set("objects",([
__DIR__"npc/fire-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        set("fire-area",1);
        setup();
}
