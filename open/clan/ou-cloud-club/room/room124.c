// Room : /open/clan/ou-cloud-club/room/room124.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你终于来到山庄的正门口，哇......好..大..的牌楼喔！
迫不及待的好奇心，驱使着你往里面走了进去。


$HIR$    ╭╯═╬═  ●      ═══╦═══□        ║         ═══╬══╬══
$YEL$  ╭╯  ═╬═  ╠══╭═══╬═══╮        ║         □    ╜    ╜
$HIY$  ╯║══╬═╰╯  ║║  ●  ║  ●  ║        ║         ║    ║    ║
$HIG$    ║  ╭╯╗║    ║    ═════    ║      ║      ● ╚══╣══╬══
$HIC$    ║╭╯  ║╰╮╭╯  ═══╦═══  ║      ║      ║ ╔══╣    ║
$HIB$    ║╯    ║  ╰╮    ╭══╯        ║      ║      ║ ║    ║    ║
$MAG$    ║    ═╯╭╯╰●  ╰═════╮  ╰═══╩═══╣ ●    ║══╩══
$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"south"     : "/open/clan/ou-cloud-club/room/room245",
		"enter"     : "/open/clan/ou-cloud-club/room/room126.c",
]) );
	set( "clan_room", "傲云山庄" );
	set( "cmkroom", 1 );
	set( "short", "$HIC$山庄$HIM$正门$NOR$" );
	set( "build", 10318 );
	set("objects", ([ /* sizeof() == 1 */
		"/open/clan/ou-cloud-club/npc/npc7" : 1,
		"/open/clan/ou-cloud-club/npc/npc10" : 1,
		"/open/clan/ou-cloud-club/npc/npc13" : 1,
]) );

	}
