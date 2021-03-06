inherit ROOM;
void create() {
	set( "short", "$HIG$梦剧场$HIR$Dream Theater$NOR$" );
	set( "owner", "devil" );
	set( "object", ([
		"file5"    : "/obj/gift/xisuidan",
		"amount9"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"amount2"  : 95,
		"amount6"  : 99999,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 99999,
		"file4"    : "/open/killer/obj/bellstar",
		"amount8"  : 1,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 81,
		"amount7"  : 99999,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
		"amount4"  : 99999,
		"file9"    : "/open/killer/obj/bellstar",
		"amount1"  : 11,
		"amount5"  : 1,
		"file8"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10074 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room177",
	]) );
	set( "long", @LONG

堪称是九０年代以来最重要也最具代表性与影响力的前卫金属乐团
，其92年所发表的专辑 <Images and Words> 为当时的前卫金属开
出新的表现形式，专辑中高层次的技术展现，使得团员纷纷成为各
方注目的焦点，也使得这张专辑顺理成章地成为前卫金属的经典代
表作之一，也是所有前卫金属乐迷的必备专辑。 

LONG);
	setup();
	replace_program(ROOM);
}
