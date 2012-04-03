// Room: /open/start/room/r3

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG
这条小路的两旁都长满了跟人差不多高的稻草，让你无
法看清楚四周的景物，看来这里很少有人经过。
你注意到南边有一间特别的建筑物，令你想一探究竟。

LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : "/open/scholar/room/enter.c",
  "east" : __DIR__"r2",
]));
  set("outdoors", "/open/start");

  setup();
}
