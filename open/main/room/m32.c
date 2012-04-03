// Room: /open/main/room/m32.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set("long", "离开了道路,你走上了一座土丘,微微的风轻拂着你,这里甚
么都没有,有着只是茫茫的芦花和蓝天. 道路则在你的西方.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m24",
  "south" : __DIR__"f19",
  "west" : __DIR__"r34",
  "east" : __DIR__"f17",
]) );

  set("outdoors", "/open/main" );


  setup();
}
