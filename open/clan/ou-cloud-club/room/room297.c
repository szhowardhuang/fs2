inherit ROOM;
void create() {
	set( "short", "$HIG$药材囤积室$NOR$" );
	set( "object", ([
		"file6"    : "/open/doctor/item/human_item",
		"amount8"  : 271,
		"amount5"  : 1500,
		"file2"    : "/open/doctor/item/sky_item",
		"file5"    : "/open/doctor/item/ground_item",
		"amount1"  : 1500,
		"amount6"  : 1500,
		"file8"    : "/open/doctor/item/sky_item",
		"file7"    : "/open/doctor/item/ground_item",
		"amount2"  : 1500,
		"file3"    : "/open/doctor/item/ground_item",
		"amount4"  : 1500,
		"file9"    : "/open/doctor/item/human_item",
		"file4"    : "/open/doctor/item/sky_item",
		"amount7"  : 237,
		"amount3"  : 1500,
		"amount9"  : 266,
		"file1"    : "/open/doctor/item/human_item",
	]) );
	set( "build", 19095 );
	set( "light_up", 1 );
	set( "owner", "skyent" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room301",
		"down"      : "/open/clan/ou-cloud-club/room/room209",
	]) );
	set( "long", @LONG
大内御医〔$HIW$风$HIR$火$HIM$山$HIG$林$NOR$〕放置药材的所在，也是傲云山庄内
的重要机秘地点，据江湖上流传，风火山林乃当今武林医术最
高的一人，只因他备有许多的神奇秘药，也因此遭受到武林上
所有同好的眼红，而他的秘药药材据说藏在此处，但入眼所见
并没有任何奇特之物．

LONG);
	setup();
	replace_program(ROOM);
}
