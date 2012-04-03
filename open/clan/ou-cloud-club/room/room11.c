inherit ROOM;
void create() {
	set( "short", "赠卫八处士--杜甫" );
	set( "owner", "andyabc" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file2"    : "/open/fire-hole/obj/p-pill",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 10,
		"amount9"  : 1,
		"amount3"  : 34,
		"amount2"  : 15,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/gblade/obj/sa-head",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file8"    : "/open/ping/obj/poison_pill",
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 20,
		"amount8"  : 17,
	]) );
	set( "build", 10215 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room234",
		"west"      : "/open/clan/ou-cloud-club/room/room5.c",
	]) );
	set( "long", @LONG


人生不相见  动如参与商  今夕是何夕  共此灯烛光

少壮能几时  鬓发各已苍  访旧半为鬼  惊呼热中肠

焉知二十载  重上君子堂  昔别君未婚  儿女忽成行

怡然敬父执  问我来何方  问答未及已  儿女罗酒浆

夜雨剪春韭  新炊间黄粱  主称会面难  一举累十觞

十觞亦不醉  感子故意长  明日隔山岳  世事两茫茫

LONG);
	setup();
	replace_program(ROOM);
}
