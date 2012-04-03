inherit ROOM;
void create() {
	set( "short", "曾经沧海楼" );
	set( "owner", "adeyzit" );
	set( "build", 16803 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room245.c",
		"up"        : "/open/clan/13_luck/room/room243",
	]) );
	set( "long", @LONG

    曾经沧海难为水，除却巫山不是云，不管新进还是已不玩的帮众
，感谢你对十三的支持，吉祥才会有今天的壮大，此楼为纪念曾经入
过十三却没机会在玩的帮众门，没有你们以前的贡献，也没有今天的
十三，虽然你以退隐江湖了，但还是感谢你。

LONG);
	setup();
	replace_program(ROOM);
}
