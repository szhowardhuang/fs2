inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "洞穴外");
  set ("long", @LONG
慢慢的走近这里一看，原来是一个山洞在这里，深黑的山洞似乎
看不见底，山洞中还传出来阵阵的吼声，不知是什么怪兽在里头，让
你止步不敢向前。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mon28",
  "enter" : __DIR__"mon52",
]));

  setup();
}
