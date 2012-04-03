// Room: /open/main/room/r18.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 10 );
	set("long", "从这儿你可以看到南边高耸直立的笔架山, 北边绵延千里的蜀
山, 传说中, 蜀山常常有剑仙出没, 一飞就飞到笔架山, 因此这儿
的人们在耕种之余, 也养成抬头看天的习惯. 道路在此呈南北走向
, 南方则是凌云村.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"r11",
  "south" : "/open/start/room/s9",
  "east" : __DIR__"m8",
  "southwest" : __DIR__"b1",
]) );

  set("outdoors", "/open/main" );


  setup();
}
