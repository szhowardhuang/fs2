// Room: /u/m/moner/water/r1.c
inherit ROOM;

void create ()
{
  set ("short", "寝房");
  set ("long", @LONG

这是魔刀新进弟子的寝房，刚入魔刀之人，因其心尚未完全至习刀
的境界，加上对环境的陌生，使的悟习刀招的效率降半，故把寝房
设在师父的左近，便于监导。一张竹藤编成的床横卧在屋子中央。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"west":__DIR__"r1.c",
]));
  set("light_up", 1);

  setup();
}
