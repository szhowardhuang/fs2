#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","总坛大厅左翼");
  set ("long", @LONG
这里是黑牙联总坛大厅左翼，为通往黑牙联最狡诈的银狼暗杀组的通道。
如此设计是为了保护大厅的安全，然而没有叶秀杀命令，他们也不敢主动保护。
然而，必须小心的是不知道何时会有人从你背后冒出来，然后给你一刀。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east":__DIR__"masterm",
  "west":__DIR__"ru7",
]));

/*  set("objects",([
        "/open/killer/npc/hu_fa2.c" : 1,
        ])); */
  setup();
}