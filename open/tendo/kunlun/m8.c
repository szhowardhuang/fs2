// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "昆仑山顶");
	set("long", @LONG
偌大的银色山谷，终年白雪皑皑，地上积了
一层薄薄的雪，虽是如此还是长了不少平地难得
一见的花草，你到处找找说不定还能找到一些珍
贵的药物。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"m1",
	"north" : __DIR__"m7",
	"west" : __DIR__"c0",
]));
	set("outdoors", "1");

	setup();
}
