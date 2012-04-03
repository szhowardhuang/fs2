inherit ROOM;
void create() {
	set( "short", "小志修练区" );
	set( "owner", "mwf" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file2"    : "/open/snow/obj/figring",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file7"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file1"    : "/open/port/obj/wolf_ring",
		"amount1"  : 1,
		"file10"   : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "build", 10001 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room113",
	]) );
	set( "long", @LONG
这里到处布满了[0;1;35m□[1m□[1m□[1m□[0m，在空气中又带着[0;1;33m□[1mC[1m□[1m□[0m，感觉
就好像到了一处剑士的修练区，在远处有一道高大的人
影，仔细一看原来是[0;1;36m□[1mp[1m□[1m□[0m在那里休息，原来这里是[0;1;36m□[1mp[1m□[1m□[0m
的[35m练功区[0m和[35m休息区[0m。
LONG);
	setup();
	replace_program(ROOM);
}
