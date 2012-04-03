inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "环山小道");
        set ("long", @LONG
小径过后，是一条比较宽大的小道，往山顶的路途还遥远，两旁
的草木仍旧稀少，青绿的颜色也慢慢转变枯黄，愈往上走，空气中所
蕴含的气息愈来愈冷，而大地中似乎又隐隐透着几许的雾气。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "westup"     : __DIR__"mon14",
        "southdown"  : __DIR__"mon12",
]));
        setup();
}

