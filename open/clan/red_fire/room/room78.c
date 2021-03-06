inherit ROOM;
void create() {
	set( "short", "飞龙居" );
	set( "owner", "andylin" );
	set( "object", ([
		"file7"    : "/open/gsword/obj/yuskirt",
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/ghost-hole/obj/flute",
		"amount9"  : 1,
		"amount7"  : 1,
		"amount3"  : 6,
		"amount1"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/obj/gift/bingtang",
		"amount2"  : 9,
		"file4"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 10048 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room74.c",
		"north"     : "/open/clan/red_fire/room/room112",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
这里是飞龙居第一大管理着的兵器房，里面放满了许许多多强
而有力的兵器，平常所找不到的通常这里都有，所以其他人是禁止
来这存取东西的。这里存放的东西通常安迪本人也很难拿到，所以
不必要的话是很少拿这里的东西的。另带一提，平常飞龙用的武器
是倚天剑和寒冰，请记得使用后放回。


LONG);
	setup();
	replace_program(ROOM);
}
