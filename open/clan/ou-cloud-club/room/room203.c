inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$云$NOR$阁$HIM$中庭$NOR$" );
	set( "build", 10034 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room210.c",
		"north"     : "/open/clan/ou-cloud-club/room/room211",
		"east"      : "/open/clan/ou-cloud-club/room/room202.c",
		"south"     : "/open/clan/ou-cloud-club/room/room193.c",
		"down"      : "/open/clan/ou-cloud-club/room/room118.c",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的二楼，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是(badcow)的南极圈牧场，右边则是水手(lnergy)的房间。

LONG);
	setup();
	replace_program(ROOM);
}
