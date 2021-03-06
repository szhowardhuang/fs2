inherit ROOM;
void create() {
	set( "short", "绿茶居大厅" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 3,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 18,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 6,
		"amount10" : 1,
		"amount8"  : 1,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 2,
	]) );
	set( "owner", "kris" );
	set( "light_up", 1 );
	set( "build", 10087 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room92",
	]) );
	set( "long", @LONG
一间布置的古色古香的房间，左右两旁摆着一列雕功精细的木制
太师椅，椅子旁边着各放有一盆小盆栽，在你的前方有着一张特
制的桃木椅，一看就知道价值不斐，想必是此居主人的座椅，这
里便是绿茶居的大厅了。  往东走可以到达前庭，东西两侧则是
通往后院。
LONG);
	setup();
	replace_program(ROOM);
}
