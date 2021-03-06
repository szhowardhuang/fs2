inherit ROOM;
void create() {
	set( "short", "剑中月木屋" );
	set( "owner", "sunsword" );
	set( "object", ([
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount2"  : 1,
		"file5"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"file1"    : "/open/port/obj/wolf_ring",
		"amount7"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/ping/obj/cloud",
	]) );
	set( "build", 9055 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room148",
	]) );
	set( "long", @LONG
屋内飘着淡淡的沉香，大气中的气流慢慢的绕着坐在椅子上
的人当你看到那个人时，你的剑心忽然失守，久久不能平息，此
时那人忽然抬头向你说道：「过来”，语气中那股不容你质疑的
口气令你身不由己的往他走了过去．

LONG);
	setup();
	replace_program(ROOM);
}
