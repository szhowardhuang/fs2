// Room: /open/main/room/cloister.c


inherit ROOM;

void create()
{
	set("valid_startroom",1);
	set("short","昆仑道观");
	set("light_up",1);
	set("long", @LONG
一间座落昆仑已久的旧道观，看起来不怎么
富丽堂皇，不过倒是窗明几净，是个适合修生养
性的好地方。

LONG
	);
	set("objects",([
	"/daemon/class/taoist/master" : 1,
		]) );
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"v4",
]));

	setup();

}
