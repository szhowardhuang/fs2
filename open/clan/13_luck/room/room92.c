inherit ROOM;
void create() {
	set( "short", "绿茶园前庭" );
	set( "object", ([
		"file6"    : "/open/gblade/obj/sa-head",
		"file7"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"file5"    : "/open/capital/obj/gold_pill",
		"file3"    : "/obj/gift/unknowdan",
		"file2"    : "/open/capital/obj/gold_pill",
		"amount9"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"amount7"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "owner", "kris" );
	set( "build", 13097 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room187.c",
		"west"      : "/open/clan/13_luck/room/room190",
		"out"       : "/open/clan/13_luck/room/room91.c",
		"south"     : "/open/clan/13_luck/room/room189.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
这里就是绿茶园的前庭，走在一条南北向的青石步道上，步道两
旁种满了许多的花，庭院的四周围则被一排高大的松树所包围，
空气中到处都充满宜人的气息，令人想逗留在此。  往南是通往
绿茶园的大厅，往东看去则给人一片雾蒙蒙的感觉，往西则是通
往绿茶园的侧厅。 
LONG);
	setup();
	replace_program(ROOM);
}
