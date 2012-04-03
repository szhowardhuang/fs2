inherit ROOM;
void create() {
	set( "short", "miffy 大楼1-3" );
	set( "owner", "miffy" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room318",
	]) );
	set( "object", ([
		"amount7"  : 1,
		"file8"    : "/open/gsword/obj1/karmband",
		"file7"    : "/open/gsword/obj1/khelmet",
		"file2"    : "/open/killer/obj/blood",
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file5"    : "/open/poison/obj/stonekey",
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/killer/obj/s_pill",
		"amount1"  : 1,
		"amount6"  : 40,
		"amount9"  : 20000,
		"file4"    : "/open/poison/obj/blue_key",
		"file9"    : "/open/killer/obj/bellstar",
		"file1"    : "/open/snow/obj/snow_token",
		"amount8"  : 1,
		"file6"    : "/open/doctor/pill/f_pill",
		"amount10" : 2000,
	]) );
	set( "light_up", 1 );
	set( "build", 11112 );
	set( "long", @LONG
这里是miffy 大楼的第一层偏厅,这里存放的东西是属于比较普通的总类
而这里又是称为miffy 平常出去战斗时的换装房,与他相同的另一个房
间则是miffy 大楼第一层之3
这里正是miffy 在换装时的第三房间,三间房间加起来的eq 刚好就是一整套
的战斗装..
LONG);
	setup();
	replace_program(ROOM);
}
