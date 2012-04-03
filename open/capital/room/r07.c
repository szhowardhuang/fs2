// Room: /open/capital/room/r07.c

inherit ROOM;

void create ()
{
  set ("short", "环宫大道");
  set ("long", @LONG
你现在越来越接近京城皇宫的大门口了, 你可以看到前方的宫门上
装饰着七排拳头大的铜环。从这里可以远远地望见东西两方的城门, 沿
着宫墙的大理基石路往两边延伸出去。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r05",
  "east" : __DIR__"r08",
]));
  set("gopath", "east");

  setup();
}
