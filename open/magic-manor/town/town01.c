inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "武器店");
        set ("long", @LONG
云风镇里面一间颇具规模的武器店，店内所贩卖的各式武器可说
是应有尽有，每件武器的品质可说是绝对有保证，架上也可以看到几
件展示的武器，但看起来是这间店的收藏的不卖品。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town07",
]));
        set("light_up", 1);
        setup();
}
