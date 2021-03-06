inherit ROOM;
void create() {
	set( "short", "太极阴阳殿" );
	set( "object", ([
		"file6"    : "/open/ping/questsfan/obj/dagger1",
		"file4"    : "/open/ping/questsfan/obj/dagger1",
		"amount5"  : 1,
		"file1"    : "/open/capital/room/king/obj/dagger1",
		"amount1"  : 1,
		"file9"    : "/open/ping/questsfan/obj/dagger1",
		"file5"    : "/open/ping/questsfan/obj/dagger1",
		"amount7"  : 1,
		"file2"    : "/open/ping/questsfan/obj/dagger1",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/capital/room/king/obj/dagger1",
		"file7"    : "/open/ping/questsfan/obj/dagger1",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ping/questsfan/obj/dagger1",
	]) );
	set( "owner", "diana" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room215",
	]) );
	set( "light_up", 1 );
	set( "build", 10016 );
	set( "long", @LONG
太极无定，阴阳无常，太极阴阳殿堂上，挂着太上老君的画像，此乃
太极阴阳之创始人之一，堂堂大殿上，充斥着轨异的气息总是令你不
由自主的颤抖，仿佛随时会被这股气息吞没，一时间你竟不知所措四
处张望...忽然...你看到不可思议的事情.吓的你连忙拔腿就跑...
LONG);
	setup();
	replace_program(ROOM);
}
