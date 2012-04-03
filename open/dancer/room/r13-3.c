// Room: /open/dancer/room/r13-3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","树林");
  set ("long", @LONG
你身处在枫树林之中，放眼望去尽是一片树海，茂密的树木几乎将
阳光完全阻挡，只有些许光线由树缝中射入。不禁令你怀疑是否走到了
与世隔绝之地。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/dancer/room/r12-3.c",

]));

  set("light_up", 0);

  setup();
}
