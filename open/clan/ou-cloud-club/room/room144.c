inherit ROOM;
void create() {
	set( "short", "$HIG$十二藏剑室$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file9"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount2"  : 1,
	]) );
	set( "build", 10952 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room180",
		"up"        : "/open/clan/ou-cloud-club/room/room145",
	]) );
	set( "long", @LONG
$HIC$十方无敌天下势    $HIB$二十余载浮与沉
    $HIR$藏锋一生了尘世    $HIY$剑术学究已天人$NOR$

墙上刻满着短短二十八字正道出了此间主人剑
术无敌于天下故藏剑于此的心情，而此间藏有
天下间十把武林中人闻之丧胆的天兵神剑，但
也因其主人弃剑从武时其被尘封于此了．

LONG);
	setup();
	replace_program(ROOM);
}
