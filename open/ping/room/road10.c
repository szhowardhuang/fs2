// Room: /open/ping/room/road10
inherit ROOM;

void create ()
{
  set ("short", "石板大桥");
  set ("long", @LONG
这里就是军营的入口了,本城的大军就在桥的那一方,你看到
桥上插满军旗,在风中洒洒飘扬着,士兵们进进出出, 似乎正在忙
着.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/soldier" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"soldier2",
  "north" : __DIR__"road6",
]));

  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
