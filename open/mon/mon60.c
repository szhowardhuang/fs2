inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "厨房");
        set ("long", @LONG
一间简陋的厨房，地上散落了一地碗具的碎片，餐桌上剩两副较
完整的碗筷，为这个房子增加了一些人气，其他的炊具散落于厨房的
每个角落，你还看到一个炉灶在厨房的另一角。
LONG);


        set("exits", ([ /* sizeof() == 4 */
        "west"      : __DIR__"mon01",
]));
        setup();
}
