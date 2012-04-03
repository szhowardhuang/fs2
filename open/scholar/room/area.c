// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "青石小径");
  set ("long", @LONG
这是通往儒门房舍间唯一的一条青石小径，小径的
南方是儒门的大门，而小径的四周有着许许多多的草坪
，在草坪的四周常可以看到儒生们在一旁读书及研究兵
法，过得十分的惬意。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"area_3.c",
  "north" : __DIR__"area2.c",
  "south" : __DIR__"r24.c",
  "east" : __DIR__"area_1.c",
]));

  setup();
}
