// Room: /open/capital/room/r34.c

inherit ROOM;

void create ()
{
  set ("short", "中央街口");
  set ("long", @LONG
这里连接着两条胡同, 东边是永福胡同, 西边则是较繁华的永安胡
同, 素有‘南市’之称, 而京城里的衙门便设在那永安胡同里。
    这里有禁卫军四处的巡逻着，所以你还是不要在城内惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/fighter" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r35",
  "west" : __DIR__"r33",
  "north" : __DIR__"r72",
  "east" : __DIR__"r36",
]));
  set("gopath", "west");

  setup();
}
