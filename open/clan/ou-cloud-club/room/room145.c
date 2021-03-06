inherit ROOM;
void create() {
	set( "short", "$HIC$练武场$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount4"  : 1,
		"file10"   : "/daemon/class/fighter/armband",
		"amount10" : 1,
		"file1"    : "/open/capital/guard/gring",
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"file5"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/prayer/obj/boris-cloth",
		"amount2"  : 1,
		"file7"    : "/open/scholar/obj/s_hands",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10933 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room146",
		"down"      : "/open/clan/ou-cloud-club/room/room144.c",
	]) );
	set( "long", @LONG
此处是帮主用来锻炼武学之地，地处封剑阁之上方，据闻此间
关有一火龙窟中的猛兽，因其受封剑阁内的十把神兵剑芒所制，一
直无法逃出此间，而帮主也常常拿此猛兽来练习武学，因帮主不喜
有旁人观看，故此间一直被禁止任何人能进入的．

LONG);
	setup();
	replace_program(ROOM);
}
