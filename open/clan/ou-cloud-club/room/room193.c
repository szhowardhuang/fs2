inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$云$NOR$阁" );
	set( "build", 10039 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room184.c",
		"east"      : "/open/clan/ou-cloud-club/room/room33.c",
		"west"      : "/open/clan/ou-cloud-club/room/room194.c",
		"north"     : "/open/clan/ou-cloud-club/room/room203",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的二楼，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是ξ雪月 风花ξ(nickm)的房间，右方是(ring)的修罗门．

LONG);
	setup();
	replace_program(ROOM);
}
