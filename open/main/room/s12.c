// Room: /open/main/room/s12.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", "这里是一片草原，割人的野草凌乱的长着，高高低低的芒
穗随着风起伏，这里应该有不少动物躲藏.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"p4",
  "west" : __DIR__"s11",
  "north" : __DIR__"d12",
  "east" : __DIR__"s13",
]) );

  set("outdoors", "/open/main" );

  setup();
}
