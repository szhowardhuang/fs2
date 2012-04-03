// Room : /open/clan/red_fire/room/room25.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$°æ$HIW$∞Àÿ‘’Û $YEL$¿§µÿπ“$HIM$°ø$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "∫Ï¡´ΩÃ" );
	set( "light_up", 1 );
	set( "long", @LONG
    


                              $HIY$®Ä®Ä®Ä    ®Ä®Ä®Ä 


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä

                                  $YEL$¿§µÿ$HIW$ÿ‘’Û$NOR$



LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "northwest" : "/open/clan/red_fire/room/room26.c",
  "east" : "/open/clan/red_fire/room/room23.c",
]) );
	setup();

	}
