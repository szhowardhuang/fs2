inherit ROOM;
void create() {
	set( "short", "$HIW$霸$HIG$刀$HIC$界$NOR$" );
	set( "owner", "freaky" );
	set( "light_up", 1 );
	set( "object", ([
		"file10"   : "/obj/gift/bingtang",
		"amount2"  : 7,
		"amount5"  : 254,
		"amount4"  : 13,
		"amount1"  : 120,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 16,
		"amount3"  : 90,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file9"    : "/obj/gift/unknowdan",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 427,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10022 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room87",
	]) );
	set( "long", @LONG

    甫踏进此地,便感觉到空气中充满着难以言谕的无匹刀气,其中蕴含了 
气吞天下的皇者霸气,柔情似水的儿女情长,义薄云天的舍己精神,以及,某 
种带着一丝不舍的淡淡遗憾,这些荡人回肠的丰富刀意,皆来自前面这座白 
净矮墙上的刀,一把历经无数生死激战,在崩坏极限边缘挣扎无数次的神器 
,相传此刀主人,多年前曾单刀赴会,已一己之力,斩尽焚天火王麾下近九成 
的精英部队,使得魔界势力产生变化,让焚天火王染指人界的计划被迫延宕 
数年,然近年来武林风平浪静,故其行事低调,甚少走动于江湖...         
                                                                 

LONG);
	setup();
	replace_program(ROOM);
}
