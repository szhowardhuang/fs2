// Room: /open/start/room/s9.c

inherit ROOM;

void create ()
{
  set ("short", "北村口");
	set( "build", 1126 );
  set ("long", @LONG
这里是凌云村的村口，从这儿可以离开凌云村，
传说在北方的蜀中城可以到达仙剑派，或许你会有这
机缘找到那像谜一般的派门。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/main/room/r18",
  "south" : "/open/start/room/s5",
]));

  set("outdoors", "/open/start");

  setup();
}
