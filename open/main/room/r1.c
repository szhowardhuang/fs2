// Room: /open/main/room/r1.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
这是来往的商队走出来的一条道路, 由于风大的关系, 路迹若隐若现
北边是北卢关，如果不是因为开采油田带来人潮, 这儿应该是人迹鲜至的
地方。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"d9",
"north" : "/open/center/room/inn",
  "east" : __DIR__"d10",
  "southwest" : __DIR__"r2",
]));
  set("outdoors", "/open/main");

  setup();
}
