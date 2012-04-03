// Room : /open/clan/red_fire/room/room21.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$°æ$HIW$∞Àÿ‘’Û $HIM$Ÿ„∑Áπ“°ø$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "long", @LONG
    


                              $HIY$®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä 


                              ®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä


                              ®Ä®Ä®Ä    ®Ä®Ä®Ä

                                  $HIM$Ÿ„∑Á$HIW$ÿ‘’Û$NOR$



LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "northwest" : "/open/clan/red_fire/room/room20.c",
  "south" : "/open/clan/red_fire/room/room22.c",
]) );
	setup();

	}
