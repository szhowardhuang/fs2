// Room: /open/dancer/room/roome2.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜梦小筑的走廊，北面的墙上有着美丽的雕塑，走到这
里你闻到阵阵花香，东面的走廊可连接到月牙儿的寝室，南
面则是花园，并有花园小径可供赏花。



LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"roome1",
  "east" : __DIR__"roome3",
  "south" : __DIR__"roomes1",
]));
 set("objects", ([ /* sizeof() == 1 */
 "/open/dancer/npc/ggirl.c" : 2,
]));

  set("light_up", 1);

  setup();
}
