inherit ROOM;
void create() {
	set( "short", "EMC 靶场" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"file6"    : "/open/doctor/pill/gnd_pill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 25,
		"amount1"  : 69,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/ping/obj/poison_pill",
		"amount7"  : 1,
		"amount9"  : 89,
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"amount3"  : 34,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 1,
		"amount6"  : 240,
		"amount2"  : 49,
		"amount4"  : 9,
	]) );
	set( "build", 10038 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room104",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
到了靶场..心中总有一种心奋..M16 步枪.打75M 175M 300M三种..
又分卧射,跪射,立射..除了步枪..还有45 手枪..M249 机枪
跟T74 机枪..还有那 六六火箭筒,跟那60 迫炮..只差那40榴弹枪
不然步兵连武器都快到齐了..
而普通步兵连七大装备跟四大业务..
参一二三四外加政战,行政.. 轮车,通讯,化学,观测,工兵,兵工,经理
LONG);
	setup();
	replace_program(ROOM);
}
