inherit ROOM;
void create() {
	set( "short", "$HIG$无  $HIB$心  $HIY$界$NOR$" );
	set( "object", ([
		"file1"    : "/open/marksman/obj/dragon_bow",
		"amount1"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/daemon/class/fighter/armband",
		"amount9"  : 1,
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/mogi/castle/obj/sholo-shield",
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/open/scholar/obj/icefan",
		"file5"    : "/open/ping/obj/gold_hand",
	]) );
	set( "build", 10413 );
	set( "light_up", 1 );
	set( "owner", "vice" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room241",
	]) );
	set( "long", @LONG
天真的笑容  已令我情动
这生中是你陪我  创出无尽的梦
                                                                                
深刻的笑容  已幻化迷梦
我无法再接近你  我心已被困于漆黑晚空
                                                                                
无心  怎会  要得痴心瞒骗
盼望你会再回看  你的眼神会将生命燃亮
                                                                                
无心  可会  再赐我光辉明天
笑问谁可  这生追寻回忆中的光明
我是宁可  每天追寻回忆中的流星

LONG);
	setup();
	replace_program(ROOM);
}
