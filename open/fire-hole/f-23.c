#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "[0;1;31m□[1m□[1m□[1ms[1m□[1m□[1m□[1m□[0m");
  set ("long", @LONG
火光四射, 烈焰直冲天顶, 使得这里的气候十分炎热, 四周都是火光,
这大概是统治着这里的怪物以无穷的力量所造成的火之结界, 当你来到了这
时, 同时被它的火光迷惑, 找不到正确的出路。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f-18.c",
  "southwest" : __DIR__"f-25.c",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/fire-liz.c" : 1,
]));

  setup();
}
