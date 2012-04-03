inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HBYEL+HIW"»Æ½ðËþ"NOR);
        set("long",@LONG
»Æ½ðËþ
LONG);
        set("exits",([
"south":__DIR__"d-07",
]));
        set("objects",([
__DIR__"npc/gold-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}
