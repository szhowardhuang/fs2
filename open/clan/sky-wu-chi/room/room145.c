inherit ROOM;
void create() {
	set( "short", "绿色水晶结界" );
	set( "owner", "palapala" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10946 );
	set( "object", ([
		"amount9"  : 1,
		"file5"    : "/open/ping/questsfan/obj/box",
		"amount7"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_legging",
		"file6"    : "/open/ping/questsfan/obj/kingblade",
		"file9"    : "/open/ping/obj/cloud_fan",
		"file7"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/daemon/class/fighter/ywhand",
		"file4"    : "/open/ping/questsfan/obj/glaze",
		"file2"    : "/open/ping/questsfan/obj/manual",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room130",
		"east"      : "/open/clan/sky-wu-chi/room/room146.c",
		"south"     : "/open/clan/sky-wu-chi/room/room76.c",
	]) );
	set( "long", @LONG
当你一走进这里时，绿色水晶马上发射出一道绿色的光射向了你
你急忙的四处闪躲，但是这样是没有用的，随着你的闪躲的速的加快
水晶所射出来的光也就越快，并且越多道，所以只好你在不得已的情
况之下，只能落慌而逃，但是只是你不知道当你逃到别的地方时，也
正有一些同样的防卫装置正在等着你，并且是威力更强，所以你受死
吧。纳命来，要怪只能怪你自己学艺不精。

LONG);
	setup();
	replace_program(ROOM);
}
