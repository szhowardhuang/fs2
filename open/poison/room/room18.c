// Room: /open/poison/room/room18
inherit ROOM;

void create ()
{
  set ("short", "魔殿侧殿");
  set ("long", @LONG
这里是冥蛊魔殿的侧殿，这里连同正殿，摆设许多奇珍
异宝，大殿内由大夜明珠装饰而成的巨火神像发出瑞彩的光
芒，整个魔殿沉浸在一片光彩之中。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/left_hufa.c" : 1,
]));
  set("light_up", 1);

  setup();
}
