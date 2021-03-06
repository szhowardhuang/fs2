inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$内房$NOR$" );
	set( "light_up", 1 );
	set( "build", 29146 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room312",
		"west"      : "/open/clan/sky-wu-chi/room/room41",
	]) );
	set( "object", ([
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/ping/obj/gold_hand",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount8"  : 1,
		"file10"   : "/open/doctor/pill/human_pill",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 33,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/ping/obj/chilin_legging",
		"file2"    : "/open/dancer/obj/linrboots",
		"amount2"  : 1,
	]) );
	set( "owner", "salicili" );
	set( "long", @LONG
房内摆着$HIG$乌木有束腰鼓腿彭牙梅花凳$NOR$,
............$HIR$红木六开光雕拐子龙纹鼓墩$NOR$,
............$HIW$黑白万花嵌螺钿酸枝木小圆桌$NOR$,
虽说$HIW$思量$NOR$只是个小小副帮主,
这房内的摆置简直可比帝王之家的还享受,
一阵脚步声急行而来,
是谁,竟然没经思量同意迳行闯入,
原来是老大$HIC$燕仔$NOR$,
燕仔一看房内,被屋内闪闪发亮的家俱刺的张不开眼,
呆了半饷,终于回过神来喝道{哇咧!帮款被你盗用多少? *_*}
LONG);
	setup();
	replace_program(ROOM);
}
