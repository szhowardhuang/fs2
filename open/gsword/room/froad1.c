#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "古木夹道");
  set ("long", @LONG
 你走在蜀山小径上,四周都是百年的古榕,参差交杂的枝干遮
敝了天空,却挡不住凉凉的风透入,你在树阴下行走,踩着枯黄的落
叶,心想: 好个蜀州的绿色隧道...
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"froad0.c",
  "east" : __DIR__"froad2.c",
]));

  setup();
}
