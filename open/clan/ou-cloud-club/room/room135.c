inherit ROOM;
void create() {
	set( "short", "$HIY$傲$HIC$云$NOR$居$NOR$" );
	set( "light_up", 1 );
	set( "build", 10854 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room15.c",
		"west"      : "/open/clan/ou-cloud-club/room/room137.c",
		"east"      : "/open/clan/ou-cloud-club/room/room136.c",
		"south"     : "/open/clan/ou-cloud-club/room/room125",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是波(perth)的无尘室，右边则是久保田利伸(bbsboss)的家．

LONG);
	setup();
	replace_program(ROOM);
}
