inherit ROOM;
void create() {
	set( "short", "$HIM$● $HIR$教主 $HIY$炼丹房$HIM$ ●$NOR$" );
	set( "owner", "fsmud" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount8"  : 2000,
		"amount4"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/marksman/obj/super_pill",
		"file6"    : "/open/killer/memory/static",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10062 );
	set( "exits", ([
		"east"      : "/open/clan/red_fire/room/room62",
		"west"      : "/open/clan/red_fire/room/room28.c",
	]) );
	set( "long", @LONG

1.红莲观世音菩萨下凡普渡众生所在之地。
2.第一代佛法传人创教，纪念观音之大德所称为红莲教。
  但是教主之名无人所知。
3.经过一次大灾难后，红莲教成为人间炼狱，面目全非。
4.数年之后一位小女孩的诞生，红莲观音显灵，
  替她取名叫......爱玫。
5.爱玫成年后，再度创教，红莲教重出，
  并且以扶助众人为教规。
6.创教不久，再次受到打击，全教被灭......。
7.之后爱玫教主与众人不负使命，再次重整红莲。
8.现在为人间仙境，众人所向往之世外桃源......。 

LONG);
	setup();
	replace_program(ROOM);
}
