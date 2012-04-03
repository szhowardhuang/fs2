inherit ROOM;
void create() {
	set( "short", "ζ妖幻装备室ζ" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "owner", "son" );
	set( "build", 10017 );
	set( "exits", ([
		"west"      : "/open/clan/demon_castle/room/room4",
	]) );
	set( "long", @LONG
此地初建, 空无一物。
LONG);
	setup();
	replace_program(ROOM);
}
