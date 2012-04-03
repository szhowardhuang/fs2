inherit ROOM;
void create() {
	set( "short", "$HIY$傲云居6n$NOR$" );
	set( "object", ([
		"amount5"  : 99999,
		"amount10" : 99999,
		"amount9"  : 99999,
		"amount6"  : 99999,
		"amount4"  : 99999,
		"file5"    : "/open/killer/obj/bellstar",
		"amount8"  : 99999,
		"file3"    : "/open/killer/obj/bellstar",
		"amount7"  : 99999,
		"file2"    : "/open/killer/obj/bellstar",
		"amount3"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"file4"    : "/open/killer/obj/bellstar",
		"file9"    : "/open/killer/obj/bellstar",
		"file10"   : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"file8"    : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
	]) );
	set( "build", 16127 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room302",
		"south"     : "/open/clan/ou-cloud-club/room/room246",
		"west"      : "/open/clan/ou-cloud-club/room/room250.c",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是语情深(zuba)的房间，右边则是炎龙(bleak)的房间。

LONG);
	setup();
	replace_program(ROOM);
}
