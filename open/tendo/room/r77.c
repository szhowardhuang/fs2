// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","空牢房");
        set("long", @LONG
在这有一张床、一张桌子和一个用来嗯嗯的茅坑，但到处都结满
了蜘蛛丝，可见这儿已很久没有关过人了。前方有一扇加装了铁条的
窗户、后方则是一扇仅容一人通过的窄门。
LONG);
set("exits", ([
        "east":__DIR__"r74",
]));
  setup();
}
