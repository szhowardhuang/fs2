inherit ROOM;
void create() {
	set( "short", "$HIC$【$YEL$黄土$HIW$路$HIC$】$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/red_fire/room/room125",
		"north"     : "/open/clan/red_fire/room/room127.c",
	]) );
	set( "outdoors", "/open/clan/red_fire" );
	set( "light_up", 1 );
	set( "long", @LONG
雨天过后，你走到一条满地$YEL$泥泞$NOR$的野外$HIW$小路$NOR$，顿时心中感到一阵不悦
，这是什么烂地方啊，脚底下都沾满了$YEL$黄色$NOR$的泥土，有一点后悔踏上这条
道路，整条路除了泥土之外，完全没有其他立足之处，但是你的$HIR$冒险$HIM$精神$NOR$
依然使你继续向前迈进。


LONG);
	setup();
	replace_program(ROOM);
}
