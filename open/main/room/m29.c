// Room: /open/main/room/m29.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set("long", "你走上了连绵的土丘,微微的风轻拂着你,这里甚么都没有,
有着只是茫茫的芦花和蓝天.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L10",
  "west" : __DIR__"m28",
  "north" : __DIR__"m20",
  "east" : __DIR__"m30",
]) );

  set("outdoors", "/open/main" );


  setup();
}
