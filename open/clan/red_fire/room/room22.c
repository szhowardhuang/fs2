// Room : /open/clan/red_fire/room/room22.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$°æ$HIW$∞Àÿ‘’Û $BLU$ø≤ÀÆπ“$HIM$°ø$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "∫Ï¡´ΩÃ" );
	set( "light_up", 1 );
	set( "long", @LONG
    


                              $HIY$®Ä®Ä®Ä    ®Ä®Ä®Ä 


                              ®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä

                                  $BLU$ø≤ÀÆ$HIW$ÿ‘’Û$NOR$



LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "north" : "/open/clan/red_fire/room/room21.c",
  "southwest" : "/open/clan/red_fire/room/room23.c",
]) );
	setup();

	}
