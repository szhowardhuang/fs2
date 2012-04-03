// Room: /open/main/room/r7.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", "这里是从驿站通往北卢关必经的要道, 东边的沼泽地一不小心会把
人整个吞进去, 西边是一片黑压压的密林, 没事最好别在此处逗留。
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r10",
  "north" : __DIR__"r5",
  "west" : __DIR__"F11",
  "east" : __DIR__"p13",
]) );

  set("outdoors", "/open/main" );

  setup();
}
