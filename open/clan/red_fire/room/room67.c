// Room : /open/clan/red_fire/room/room67.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$【$HIC$护城河$HIW$】$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room66",
		"east"      : "/open/clan/red_fire/room/room51.c",
	]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 0 );
	set( "long", @LONG

               $HIC$ ╮  ╮  ╮  ╮
                ╰╮╰╮╰╮╰╮
                  ╰╮╰╮╰╮╰╮
                    ╰╮╰╮╰╮╰╮
                      ╰╮╰╮╰╮╰╮
                        ╰╮╰╮╰╮╰╮
                          ╰  ╰  ╰  ╰

                        $HIY$美人愁

                    $HIM$涓涓河水飘红莲，
                    睹物思情伤心头，
                    城中美人单相念；
                    孤独哀愁又谁知。  $HIR$爱玫 $HIW$笔$NOR$


LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "红莲教" );

	}
