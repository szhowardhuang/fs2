inherit ROOM;
void create() {
	set( "short", "湖心小筑" );
	set( "owner", "dancer" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 348,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/doctor/pill/human_pill",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10020 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room118.c",
		"west"      : "/open/clan/13_luck/room/room367",
		"south"     : "/open/clan/13_luck/room/room194.c",
		"up"        : "/open/clan/13_luck/room/room238.c",
		"north"     : "/open/clan/13_luck/room/room195.c",
	]) );
	set( "long", @LONG
这是一个与世隔绝的地方,四周的空气弥漫着花香,树林传来阵阵的鸟语,
这里远离了世俗的尘埃,是一个稀少人会知道的世外仙境,没有战争只有
和平,也因为这里的宁静正好是一个让人能够快速修养身心的好地方,
如果你有足够的缘分到达此世外仙境,希望你自己可以保持此仙境的宁静和平.
LONG);
	setup();
	replace_program(ROOM);
}
