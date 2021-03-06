inherit ROOM;
void create() {
	set( "short", "$HIR$死灵$HIC$刀$NOR$谷" );
	set( "object", ([
		"amount8"  : 1386,
		"file6"    : "/open/gblade/obj/dragon_book",
		"file4"    : "/open/ping/obj/ring-2",
		"amount6"  : 1,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 247,
		"file5"    : "/open/scholar/obj/icefan",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 1,
		"file2"    : "/open/port/obj/wolf_ring",
		"amount7"  : 293,
		"file3"    : "/open/main/obj/shiblade",
		"amount5"  : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "moblade" );
	set( "build", 10019 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room10",
		"east"      : "/open/clan/ou-cloud-club/room/room107.c",
	]) );
	set( "long", @LONG
刀邪．不二刀练刀之地，自从刀邪不二刀加入魔刀门之后，立
志要夺回失传已久的妖刀，却苦于对刀的领悟不够，无法杀入魔刀
禁地而一举夺得曾经让世人闻之色变的妖刀，所以就在此地静思所
学，当有天破关而出时，也就是妖刀现世了！！

LONG);
	setup();
	replace_program(ROOM);
}
