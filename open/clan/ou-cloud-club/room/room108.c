// Room : /open/clan/ou-cloud-club/room/room108.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$天门$NOR$(没出口)" );
	set( "cmkroom", 1 );
	set( "long", @LONG

$HIC$        ╔═══╦═══╝$HIM$           ╭══╮╭══╮
$HIC$                ║        $HIM$           ╠══╣╠══╣
$HIC$        ╔═══╬═══╝$HIM$           ╠══╯╰══╣
$HIC$              ╔╝╗      $HIM$           ║            ║
$HIC$            ╔╝  ╚╗    $HIM$           ║            ║
$HIC$        ╚═╝      ╚═╝$HIM$           ║            ║$NOR$

LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "clan_room", "傲云山庄" );
	setup();

	}
