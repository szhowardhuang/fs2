// Room: /open/main/room/F4.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
这里一望无际的密林，四周伸手只见四指, 往西似乎稍微透出点亮光
那边的树应该比较少一些吧? 南边高高耸立着一座高山, 山顶不知是云还
是雪, 一片白茫茫, 那里难道是蜀山?
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f4",
  "north" : __DIR__"F1",
  "east" : __DIR__"F5",
]));

	setup();
}
