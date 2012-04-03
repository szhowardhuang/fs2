inherit ROOM;
void create() {
	set( "short", "小喵兵器房" );
	set( "owner", "cong" );
	set( "object", ([
		"file4"    : "/open/soldier/obj/blood",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/capital/obj/blade2",
		"file10"   : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount10" : 1,
		"file2"    : "/open/beggar/obj/gstaff",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/japan/obj/super-blade",
		"file9"    : "/open/magic-manor/obj/golden-ball",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
	]) );
	set( "build", 10176 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room99",
	]) );
	set( "long", @LONG
这是一小喵专用的兵器房 , 这里放着各式各样的兵器 , 为
世界兵器最为齐全之地 , 你看到各种奇怪的兵器 , 所谓工欲善
其事 ,必先利其器 , 看来 ,你也该为自己选把像样的武器 , 好
闯荡江湖 .你可以看看(list)参观一下这里的兵器 ?

LONG);
	setup();
	replace_program(ROOM);
}
