inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$□$HIY$防具所$HIB$III$NOR$" );
	set( "owner", "lts" );
	set( "object", ([
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount10" : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
	]) );
	set( "build", 10210 );
	set( "exits", ([
		"love"      : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room169.c",
		"east"      : "/open/clan/sky-wu-chi/room/room109.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
当你一走近这个地区的时候...有一阵阵的微风吹来...
打从心底感到一振凉意...让你在仿佛徜徉在大海般的感觉...
正当你想离开这地方的时候你发现你突然全身出不了力了...
你这时才恍然大悟lts这小子居然为了防止eq被偷
居然在这房间下了迷药...心想他真是狠毒...


LONG);
	setup();
	replace_program(ROOM);
}
