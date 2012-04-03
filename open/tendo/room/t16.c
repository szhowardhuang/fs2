// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "修行房");
	set("long", @LONG
地板铺着一层层的草席。四周相当地宽敞，没有
其他的杂务扰人，是个冥想的好地方。你可以看到不
少的天道弟子坐在这冥想打坐。

LONG
	);
	set("objects",([
	"/open/tendo/npc/boy.c" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"t06",
	"west" : __DIR__"t15",
	"south" : __DIR__"t14",
]));

	set("light_up",-1);
	setup();
}
