inherit ROOM;
void create() {
	set( "short", "小敏练功房" );
	set( "object", ([
		"file5"    : "/open/ping/obj/gold_hand",
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"amount3"  : 3,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount10" : 1,
		"file9"    : "/daemon/class/fighter/figring",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"amount2"  : 4,
		"amount6"  : 1,
		"file2"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "owner", "mming" );
	set( "light_up", 1 );
	set( "build", 10054 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room197.c",
		"west"      : "/open/clan/ou-cloud-club/room/room235",
	]) );
	set( "long", @LONG
在未进入房间前，阵阵的寒气已逼迫让人透不过气来，推开
厚重的石门进入房间内，迎面而来的的凛然气息更是让武功底子
较差的人猛打哆嗦，不难看出屋子的主人所练的内功乃是走因寒
路线。屋子中什么都没有，唯一引人注目的是摆设在屋子中央的
一张特殊的床，一张散发出高热的床，看来是小敏用来练内功的
法宝。

LONG);
	setup();
	replace_program(ROOM);
}
