inherit ROOM;
void create() {
	set( "short", "姜母鸭" );
	set( "owner", "oasis" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/u/d/dhk/questsfan/obj/diamond_armor",
		"amount1"  : 1,
		"file10"   : "/open/mogi/village/obj/mogi_ring",
		"amount10" : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file2"    : "/u/d/dhk/questsfan/obj/diamond_boots",
		"amount2"  : 1,
		"file8"    : "/open/capital/obj/blade2",
		"file1"    : "/u/d/dhk/questsfan/obj/diamond_belt",
	]) );
	set( "build", 16000 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room152",
	]) );
	set( "long", @LONG
  火焰鸭在傲云的第一个家,他的好朋友小雯就住在隔壁,损友slayer住在斜对面
火焰鸭是一只相当有义气的鸭子,虽然被他的损友slayer杀了很多脑细胞,但是仍然
相当照顾他,虽然火焰鸭已经很老了,不过他传授了他的技能给小敏让小敏在天道派
发扬光大.目前正在闭关中,有朝一日将会重出江湖.

  
LONG);
	setup();
	replace_program(ROOM);
}
