inherit ROOM;
void create() {
	set( "short", "虚拟海洋" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room47",
		"east"      : "/open/clan/13_luck/room/room32.c",
		"south"     : "/open/clan/13_luck/room/room34.c",
	]) );
	set( "long", @LONG

    漂浮在海上也有好几个对时了，妳始终找不路，正当妳在烦恼时
，突然发现前方好像有人的吵杂声，可是妳在怎么用力看还是看不道
路地，于是妳就依着声音的方向划去，声音越来越大声了，看来朝着
这方向去应该是能找到出路了。    

LONG);
	setup();
	replace_program(ROOM);
}
