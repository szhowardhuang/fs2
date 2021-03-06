// Room: /open/main/room/r43.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
  set ("long", @LONG
你走在灰尘滚滚的石子路上，这里已经相当接近苗疆了，你
的西方，即是本朝西南重镇: 平南城. 本朝在此驻有重兵，以防
范苗疆来的侵略. 道路在此则往北往东和往西.
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/wu/npc/k_tiger" : 1,
  "/open/main/obj/torch" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L24",
  "north" : __DIR__"r39",
  "west" : __DIR__"r42",
  "east" : __DIR__"r44",
]));

  setup();
}
