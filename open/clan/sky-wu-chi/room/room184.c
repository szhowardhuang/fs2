inherit ROOM;
void create() {
	set( "short", "夏雷的休息室" );
	set( "object", ([
		"file5"    : "/u/d/dhk/questsfan/obj/diamond_cloak",
		"amount4"  : 1,
		"file7"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"file3"    : "/u/d/dhk/questsfan/obj/diamond_hands",
		"amount2"  : 1,
		"amount7"  : 1,
		"file6"    : "/u/d/dhk/questsfan/obj/diamond_hairpin",
		"file10"   : "/u/d/dhk/questsfan/obj/diamond_boots",
		"amount10" : 1,
		"file1"    : "/u/d/dhk/questsfan/obj/diamond_skirt",
		"amount1"  : 1,
		"file9"    : "/u/d/dhk/questsfan/obj/diamond_legging",
		"file2"    : "/u/d/dhk/questsfan/obj/diamond_belt",
		"amount3"  : 1,
		"file8"    : "/open/prayer/obj/boris-hat",
		"amount8"  : 1,
		"amount9"  : 1,
		"file4"    : "/u/d/dhk/questsfan/obj/diamond_armor",
		"amount5"  : 1,
	]) );
	set( "build", 10161 );
	set( "light_up", 1 );
	set( "owner", "gendor" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room183.c",
	]) );
	set( "long", @LONG
    这里是一间神秘的地下室，里面立有十八尊金色的金人，每一尊金人都
摆了一个不同的姿势，而它们的表情也随着动作而有所不同。两旁烧着熊
熊的大火，让这个休息室亮的像白天一样,夏雷都在这边练功
跟休息用的地方0
LONG);
	setup();
	replace_program(ROOM);
}
