// Room : /open/clan/red_fire/room/room66.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$【$HIC$护城河$HIW$】$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 0 );
	set( "long", @LONG


 
                          $HIC$╭  ╭  ╭  ╭ 
                        ╭╯╭╯╭╯╭╯
                      ╭╯╭╯╭╯╭╯
                    ╭╯╭╯╭╯╭╯
                  ╭╯╭╯╭╯╭╯
                ╭╯╭╯╭╯╭╯
                ╯  ╯  ╯  ╯

                        $HIY$假人生

                    $HIM$虚虚实实虚如实，
                    真真假假真如假，
                    虚实真假皆已空；
                    人生不过一场梦。  $HIR$爱玫 $HIW$笔$NOR$


LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "红莲教" );
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/red_fire/room/room63.c",
		"east"      : "/open/clan/red_fire/room/room67",
]) );
	setup();

	}
