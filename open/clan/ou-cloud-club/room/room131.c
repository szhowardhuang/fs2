inherit ROOM;
void create() {
	set( "short", "$HIY$¿ñÏë$HIC$´¢²ØÊÒ$NOR$" );
	set( "object", ([
		"file4"    : "/open/doctor/item/sick_item",
		"file8"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1060,
		"file7"    : "/open/gblade/obj/sa-head",
		"amount8"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/hall",
	]) );
	set( "build", 10494 );
	set( "long", @LONG

$HIY$      ¨^¨[¨^¨T¨T¨j¨T¨T¨a    ¨U    ¨X¨T¨T¨[
      ¨X¨p¨a    ¨U      ¨T¨j¨p¨j¨T¨d¨T¨T¨g
      ¨a¨U  ¨T¨T¨p¨T¨T  ¨X¨a¨U¨^¨[¨d¨T¨T¨g
      ¨X¨p¨a    ¨U          ¨a    ¨^¨T¨T¨a
      ¨a¨U      ¨U      ¨X¨^¨[¨^¨T¨[¨^¨T¨[
        ¨a¨^¨T¨T¨m¨T¨T¨a¨a  ¨^¨T¨T¨T¨T¨a$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
