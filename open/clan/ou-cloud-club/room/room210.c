inherit ROOM;
void create() {
	set( "short", "$HIC$南极圈牧场$NOR$" );
	set( "object", ([
		"file6"    : "/open/firedancer/npc/eq/r_cloth",
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_neck",
		"amount8"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_leg",
		"file4"    : "/open/firedancer/npc/eq/r_armbands",
		"file2"    : "/open/firedancer/npc/eq/r_belt",
		"file5"    : "/open/firedancer/npc/eq/r_head",
		"amount2"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_cape",
	]) );
	set( "owner", "del" );
	set( "build", 11802 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room203",
	]) );
	set( "long", @LONG
  
    眼前是一座风景优美的牧场，除了可以远眺绵延不绝的高
山，不远处还有一座清澈见底的人工湖，这里的牛牛就是在这
样的环境下才能只只头好壮壮，突然间有两只小牛跑到你脚边
磨蹭，可爱的模样让人不禁发出会心一笑。
□
LONG);
	setup();
	replace_program(ROOM);
}
