inherit ROOM;
void create() {
	set( "short", "武器交换地" );
	set( "object", ([
		"file5"    : "/obj/gift/xisuidan",
		"file2"    : "/open/gblade/obj/dragon_book",
		"file9"    : "/obj/gift/unknowdan",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount7"  : 13,
		"amount8"  : 1,
		"file7"    : "/open/ping/obj/poison_pill",
	]) );
	set( "owner", "roar" );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room186",
	]) );
	set( "long", @LONG
遍地的宝刀名剑，不难想像你以来到了一个武器地方，但是遍地的刀剑却无
人看管，聪明的你也知道这不单存，然而往里面走去，却发现一棵树，它名叫”
[0;1;32m□[1mi[1m□[1mC[1m□[1m□[0m”据说可以”[0;1;35m□[1mH[1m□[1m□[1m□[1m□[1m□[1m□[0m”但是你所要换的东西必须拿比那东西好的条件，
此时你发现有一双刀正掉下来，有一个人在那双手高举的接下，

LONG);
	setup();
	replace_program(ROOM);
}
