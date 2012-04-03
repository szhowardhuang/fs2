inherit ROOM;
void create() {
	set( "short", "$HIY$²Ø$HIR$Áú$NOR$¾Ó$NOR$" );
	set( "owner", "kbo" );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room118.c",
		"west"      : "/open/clan/ou-cloud-club/room/room120",
	]) );
	set( "long", @LONG
$HIY$¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¡¡¡¡¨U    ¨U
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¨T¨j¨T¨j¨T¨d¨T¨T¨a
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¨U¨^¨j¨a¨U¨^¨T¨T¨[
¡¡¡¡¡¡¡¡¡¡  ¡¡¡¡¡¡¨^¨T¨p¨T¨a¨X¨T¨T¨a
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¨X¨T¨m¨T¨[¨d¨T¨T¨T
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¨d¨T¨T¨T¨g¨d¨T¨T¨T
¡¡¡¡¡¡¡¡¡¡  ¡¡¡¡¡¡¨d¨T¨T¨T¨g¨d¨T¨T¨T
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¨a  ¨T¨T¨a¨^¨T¨T¨T$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
