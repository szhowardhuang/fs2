inherit ROOM;
void create() {
	set( "short", "妖幻披掮室" );
	set( "owner", "jtl" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/wu/npc/obj/armband",
		"file9"    : "/open/ping/obj/ring-2",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"amount8"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room312",
		"south"     : "/open/clan/13_luck/room/room301.c",
	]) );
	set( "build", 11298 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，为闻名无不吓破胆的千年树妖舞风扬身上所有的，此妖有
千年之功力，长年在长白山上修练，法术更是无人能敌，与他为敌只会
一肚子大便的状态，尤其是虚弱，所以他的防具不是说有就有的，也要
看有没有人敢去打为了那一件[0;1;33m□[1m□[1m□[1m□[1m□[1m□[1m□[1mz[0m。

LONG);
	setup();
	replace_program(ROOM);
}
