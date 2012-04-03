// Room : /open/clan/red_fire/room/room13.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "clan_room", "ºìÁ«½Ì" );
	set( "no_transmit", 1 );
	set( "short", "$HIY$¡¾$HIR$ºìÁ« $HIC$´óÃÅ$HIY$¡¿$NOR$" );
	set( "cmkroom", 1 );
	set( "long", @LONG

          $HIR$¨X¨T¨T¡õ ¨T¨j¨T    ¡ñ ¨T¨T¨p¨p¨T¨T ¨T¨T¨p¡ñ¨T  ¨U
          $YEL$¨U    ¨r   ¨U    ¨T¨T¨[¨T¨T¨p¨T¨T  ¨T¨T¨p¨T¨T¨t¨s¨T¨T
          $HIY$¨^¨T¨j¨s   ¨U      ¨q¨s¨X¨T¨p¨T¨[  ¨q¨T¨s¨T¨[¨U    ¨U
          $HIG$¨X¨T¨s  ¨r ¨t¨r  ¨T¨m¨[¨c¨T¨p¨T¨f  ¨s¡õ¨q¨T¨s¨t¨r¨q¨s
          $HIC$¨U      ¨U   ¨U    ¨q¨s¨^¨T¨p¨T¨s  ¨T¨T¨p¨T¨T  ¨t¨r
          $HIB$¨^¨T¨T¨T¨s   ¨U  ¨q¨s  ¨T¨T¨p¨T¨T      ¨U    ¨q¨s¨t¨r
          $HIM$ ¡ñ ¡ñ ¡ñ¨T¨T¨m¨T¨t¨T¨T¨T¨T¨T¨T¨T¨s¨t¨T¨s  ¨T¨s    ¡ñ $NOR$


LONG);
	set( "exits", ([ /* sizeof() == 2 */
  "enter" : "/open/clan/red_fire/room/room2",
  "south" : "/open/clan/red_fire/room/room14",
]) );
	setup();

	}
