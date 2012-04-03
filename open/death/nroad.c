// Room: /open/death/nroad.c

inherit ROOM;

void create ()
{
  set ("short", "阎罗北路");
  set ("long", @LONG

这是一间什么都没有的房间。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/death/office",
  "west" : "/open/death/bank.c",
  "south" : "/open/death/square",
  "east" : "/open/death/blackshop",
]));

  set("light_up", 1 );
  set("no_magic", 1 );
  set("no_fight", 1 );

  setup();
}
