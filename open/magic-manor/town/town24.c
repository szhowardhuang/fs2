inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "东来桥");
        set ("long", @LONG
位处在云风镇的东边重要道路上的小桥，若要进入此镇，此桥是
非经过不可的，这座桥是用石头的材质铺成，历经几千几万个风风雨
雨的日子仍然是如此坚固无比。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"      : __DIR__"town18",
        "south"      : __DIR__"town30",
        "east"       : __DIR__"town39",
]));
        setup();
}
