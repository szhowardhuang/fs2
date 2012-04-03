inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIY"狂风七星阵"NOR);
  set ("long", @LONG

    你走进这里, 突然一阵狂风吹起, 括起漫天风沙, 你置
身在这疾风当中, 顿感一阵晕炫, 眼前似乎有几盏灯火, 指
引你走出此地。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "天枢" : __DIR__"mi02.c",
  "天璇" : __DIR__"mi_dead.c",
  "天玑" : "/open/main/room/maiu-1.c",
  "天权" : __DIR__"mi_dead.c",
  "玉衡" : __DIR__"mi01.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/killer.c" : 2,
]));
  set("light_up", 1);
  set("no_transmit",1);

  setup();
}
