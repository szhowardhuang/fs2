// Room : /open/clan/red_fire/room/room23.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$°æ$HIW$∞Àÿ‘’Û $MAG$Ùﬁ¿◊π“$HIM$°ø$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "∫Ï¡´ΩÃ" );
	set( "light_up", 1 );
	set( "long", @LONG
    


                              $HIY$®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä 


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä

                                  $MAG$Ùﬁ¿◊$HIW$ÿ‘’Û$NOR$



LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "northeast" : "/open/clan/red_fire/room/room22.c",
  "west" : "/open/clan/red_fire/room/room25.c",
]) );
	setup();

	}
