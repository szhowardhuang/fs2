// Room: /u/e/eiei/work/troom_2.c
inherit ROOM;

void create ()
{
  set ("short", "林间小路");
  set ("long", @LONG
    走着走着，你发现似乎越往山上走，路上所看到的
    奇花异草种类越来越怪异，其中有一些花的颜色在平常
    是根本不可能看到的，而且花所飘散出来的芳香也是你
    从来没有闻过的，闻了以后竟让人有一种飘飘欲仙的感
    觉！
LONG);

  set("outdoors", "/u/e/eiei/workroom");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"troom_3.c",
  "south" : __DIR__"troom_1.c",
]));

  setup();
}
