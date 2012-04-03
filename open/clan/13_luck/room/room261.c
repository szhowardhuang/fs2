inherit ROOM;
void create() {
	set( "short", "‘桃花森林’ " );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room260",
		"north"     : "/open/clan/13_luck/room/room247.c",
	]) );
	set( "long", @LONG
再走进桃花林里，依稀听见远方传来稀稀苏苏的声音。对于刚刚很多的
岔路就不太那么在意了。只是在桃花林里的出口好像有点过多，感觉似乎是
有人故意排这个阵局的，但是这只是个虚晃的手法而已，坚持下去将会走出
这片桃花林。
LONG);
	setup();
	replace_program(ROOM);
}
