// Room: /u/d/dhk/questsfan/rm4
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林"HIC"翗"NOR"路");
  set ("long", @LONG
这一段路上，竟让你看到一只身形好像凤凰而其全身都
是碧绿色的不知名的鸟。而且牠在飞翔之迅速、优美，令人
赞叹。也因为这样的奇遇促使你对这一段路更好奇，继续的
探险下去。

LONG);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm3",
  "eastup" : __DIR__"rm5",
]));

  setup();
}
