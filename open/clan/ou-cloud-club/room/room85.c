// Room : /open/clan/ou-cloud-club/room/room85.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$天山$NOR$山顶" );
	set( "no_clean_up", 0 );
	set( "long", @LONG

$HIC$    ╔═══╦═══╝$HIY$             ║        $HIG$      ═╦═ ═╦══
$HIC$            ║        $HIY$             ║        $HIG$        ║   ╔╝═╗
$HIC$    ╔═══╬═══╝$HIY$     ║      ║      ║$HIG$        ║   ╠══╣
$HIC$          ╔╝╗      $HIY$     ║      ║      ║$HIG$        ║   ╠══╣
$HIC$        ╔╝  ╚╗    $HIY$     ║      ║      ║$HIG$      ╗║   ╚╦╦╝
$HIC$    ╚═╝      ╚═╝$HIY$     ╚═══╩═══╝$HIG$      ╚╝   ═╝╚═$NOR$

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 1 */
  "down" : "/open/clan/ou-cloud-club/room/room84",
]) );
	set( "clan_room", "傲云山庄" );
	set( "no_transmit", 1 );
	setup();

	}
