// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","监牢地道");
        set("long", @LONG
这儿左右都是一间间的牢房，但都是空的。真不知这些牢房是要
用来干什么的?
LONG);
set("exits", ([
        "south":__DIR__"r74",
	"north":__DIR__"r72",
	"east":__DIR__"r79",
	"west":__DIR__"r76",
]));
  setup();
}
