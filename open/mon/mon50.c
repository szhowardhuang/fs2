inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "接天境");
        set ("long", @LONG
登上这里，这里的景色真是你所见过最美的了，缥渺的云雾轻轻
的漫舞在你的身旁，七色的炫光直通天际，沉浸在这样的景色之中，
你不禁有些迷失了，却已忘了你是身处梦中还是现实之中。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "down"    : __DIR__"mon42",
]));
        setup();
}
