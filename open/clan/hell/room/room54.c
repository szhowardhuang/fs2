inherit ROOM;
void create() {
	set( "short", "$HIY$废琳$HIG$安养院$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount9"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/tendo/obj/chaosbelt",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file8"    : "/open/wu/npc/obj/armband",
		"file2"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "kalin" );
	set( "build", 10074 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room55.c",
		"south"     : "/open/clan/hell/room/room63.c",
		"east"      : "/open/clan/hell/room/room46",
		"west"      : "/open/clan/hell/room/room4.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
kalin自从转到射手后...发觉嫁错郎了..
原来射手之前的wiz是aol那只^(OO)^头..
sigh 1000000000
好在损友min有帮射手想了一写quest给nike..
虽然min平时仗势欺人..无恶不作..
但这次还是要感谢他吧..
或许是他觉得罪孽深重..藉此来赎罪吧..
anyway...kalin就是在此安养他的余生了..
如果哪天你看到他..不妨拍拍他的头..安慰一下..

LONG);
	setup();
	replace_program(ROOM);
}
