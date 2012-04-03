inherit ROOM;
void create() {
	set( "short", "$HIY$傲$HIC$云$NOR$居" );
	set( "object", ([
		"file10"   : "/open/doctor/obj/feather",
		"file2"    : "/open/doctor/obj/feather",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/doctor/obj/feather",
		"amount3"  : 1,
		"file5"    : "/open/doctor/obj/feather",
		"amount7"  : 1,
		"file1"    : "/open/doctor/obj/feather",
		"file9"    : "/open/doctor/obj/feather",
		"file4"    : "/open/doctor/obj/feather",
		"file8"    : "/open/doctor/obj/feather",
		"amount6"  : 1,
		"file7"    : "/open/doctor/obj/feather",
		"amount5"  : 1,
		"file3"    : "/open/doctor/obj/feather",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10559 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room200",
		"jump"      : "/open/clan/ou-cloud-club/room/room305",
		"west"      : "/open/clan/ou-cloud-club/room/room198.c",
		"north"     : "/open/clan/ou-cloud-club/room/room246.c",
		"south"     : "/open/clan/ou-cloud-club/room/room18.c",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是小敏(mming)练功的房间，右边则醉情忘月(breeze)的青山房．

LONG);
	setup();
	replace_program(ROOM);
}
