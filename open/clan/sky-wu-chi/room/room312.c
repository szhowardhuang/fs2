inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$佛堂$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/prayer/obj/boris-cloth",
		"amount8"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/scholar/obj/icefan",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/dancer/obj/yuawaist",
		"file2"    : "/open/scholar/obj/s_hands",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/daemon/class/fighter/armband",
		"amount9"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 11956 );
	set( "light_up", 1 );
	set( "item_desc", ([
		"念佛机" : @ITEM
思量就随着这台念佛机在这边念佛  ^^
ITEM,
	]) );
	set( "owner", "salicili" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room132",
	]) );
	set( "long", @LONG


    尔时世尊,从肉髻中,
    涌百宝光,光中涌出,
    千叶宝莲,有化如来,
    坐宝花中,顶放十道,
    百宝光明,一一光明,
    皆遍示现,十恒河沙,
    金刚密迹,擎山持杵,
    遍虚空界,大众仰观,
    畏爱兼抱,求佛哀佑,
    一心听佛,无见顶相,
    放光如来,宣说神咒.


南无萨怛他  苏伽多耶  阿啰诃帝
....................
....................
角落摆台小小黑色的机器,你仔细观察发现是台<念佛机>.


LONG);
	setup();
	replace_program(ROOM);
}
