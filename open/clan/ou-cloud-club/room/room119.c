// Room : /open/clan/ou-cloud-club/room/room119.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

            $HIM$®p®p®T®T®p®X®[®^®T®[®^®T®m®T®a®X®T®T®T®[
            ®U®U    ®U®X®[    ®U®X®m®T®m®[®U®T®T®p®U
            ®U®U    ®U®^®[®d®T®a®U®X®p®[®U®U®X®[®U®U
            ®U®^®T®T®a®^®a®U  ®[®U®U®U®U®U®U®^®a®p®U
            ®^®T®T®T®a®^®^®^®T®a®a®a®a®^®a®^®^®a®m®a$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "∞¡‘∆…Ω◊Ø" );
	set( "exits", ([ /* sizeof() == 3 */
		"down"      : "/open/clan/ou-cloud-club/room/room118.c",
		"east"      : "/open/clan/ou-cloud-club/room/room13.c",
		"up"        : "/open/clan/ou-cloud-club/room/room132.c",
		"daimon"    : "/open/clan/ou-cloud-club/room/room252",
		"west"      : "/open/clan/ou-cloud-club/room/room4.c",
]) );
	set( "light_up", 1 );
	set( "short", "$HIC$œ¿$HIM$ªÍ$HIR$“Â$HIB$∆«$NOR$" );
	set( "owner", "ripken" );
	set( "object", ([
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"amount2"  : 1,
		"file5"    : "/open/killer/headkill/obj/e_dag",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/killer/headkill/obj/w_dag",
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"file2"    : "/open/killer/headkill/obj/i_dag",
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 11063 );
	set( "cmkroom", 1 );
	setup();

	}
