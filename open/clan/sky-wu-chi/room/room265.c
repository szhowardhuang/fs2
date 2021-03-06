inherit ROOM;
void create() {
	set( "short", "$HIW$亡$HIR$剑$HIB$冢$NOR$" );
	set( "owner", "mudu" );
	set( "object", ([
		"amount3"  : 33,
		"amount8"  : 6,
		"file9"    : "/obj/gift/xisuidan",
		"file7"    : "/open/ping/obj/poison_pill",
		"amount10" : 7,
		"amount7"  : 18,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 220,
		"file4"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 20,
		"amount9"  : 1,
		"amount4"  : 80,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/mogi/castle/obj/blood-water",
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 10,
		"amount5"  : 9,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "build", 10113 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room246",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
踏入此处弥漫着一股肃杀的气愤，地上插满了各式各样的断剑
，看来仿佛是一个剑冢，在不远处立了一个石碑，上面写着此乃
剑圣=>(真．树头)所葬剑之地，毕生所用之剑皆在此处，特此立
此石碑为之吊祭！你带着景仰的神情为此感到凄壮的气氛。
LONG);
	setup();
	replace_program(ROOM);
}
