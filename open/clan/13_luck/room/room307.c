inherit ROOM;
void create() {
	set( "short", "小魔女的魔法绎站" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/ping/obj/chilin_legging",
		"file1"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"amount9"  : 1,
		"file5"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
		"file10"   : "/open/gsword/obj/may_ring",
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file9"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 10059 );
	set( "owner", "mei" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room240",
	]) );
	set( "long", @LONG

@>>-  魔 法 驿 站  -<<@
这是我沈思，发呆，练功，补充精力的地方一进入此处，淡蓝色系的
房间陈设，使人觉得精神气爽，仿佛置身在蔚蓝的黄金海岸，在这不
知不觉中，功力就如有神助般的加速倍增

**出发 ------ 总要有个方向**
**向 刀魂幽姬 的方向出发吧**


LONG);
	setup();
	replace_program(ROOM);
}
