// Room: /u/m/moner/room/room10.c
inherit ROOM;

void create ()
{
  set ("short", "长廊");
  set ("long", @LONG

走进这里, 是一条长廊, 往前通往后院, 而往两旁也各有一条走道,长廊上铺着上
好的红毯, 两旁的墙上挂着几盏油灯。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room16.c",
  "north" : __DIR__"room13.c",
  "east" : __DIR__"room23.c",
  "northwest" : __DIR__"room2.c",
]));
  set("light_up", 1);

  setup();
}
