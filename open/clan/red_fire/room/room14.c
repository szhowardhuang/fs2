// Room : /open/clan/red_fire/room/room14.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"down"      : "/open/clan/red_fire/room/room157",
		"north"     : "/open/clan/red_fire/room/room13",
]) );
	set( "cmkroom", 1 );
	set( "clan_room", "ºìÁ«½Ì" );
	set( "short", "$HIC$¡¾$HIW$»¨¸ÚÑÒ $GRN$Ê¯½×$HIC$¡¿$NOR$" );
	set( "outdoors", "/open/clan/red_fire" );
	set( "long", @LONG

                       $HIY$¨X¨T¨h¨h¨T¨T¨T¨T¨T¨T¨T¨T¨T¨h¨h¨T¨[
                       ©¸©´©¦©¦ $HIR$ºì     Á«     ½Ì $HIY$©¦©¦©°©¼
                         ¨\¨n¨n¨T¨T¨T¨T¨T¨T¨T¨T¨T¨n¨n¨_
                          $HIC$ ¡ì ¡ì                 ¡ì ¡ì
                           ¡ì ¡ì                 ¡ì ¡ì
                           ¡ì ¡ì                 ¡ì ¡ì
                           ¡ì ¡ì                 ¡ì ¡ì
                           ¡ì ¡ì                 ¡ì ¡ì
                           ¡ì ¡ì                 ¡ì ¡ì
                         $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y$GRN$¨q©¤©¤¨r
                       $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y$YEL$¨q¨r$GRN$©¦©¦©¦
                     $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y$YEL$¨q¨r$GRN$¨q©¤¨r©¦
                   $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y  $GRN$¨q©¤©¤¨r©¦$YEL$¨q¨r
                 $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y$GRN$¨q©¤¨r©¦  ©¦©¦¨q©¤¨r
               $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y  $GRN$©¦¨q©¤©¤©¤¨r©¦©¦  ©¦
             $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y  $GRN$¨q©¤¨r©¦  ©¦©¦©¦©¦©¦©¦
           $YEL$¨q¨r$HIW$¨V¨T¨T¨T¨T¨T¨T¨T¨T¨T¨Y$YEL$¨q¨r$GRN$©¦©¦©¦$YEL$¨q¨r$GRN$©¦©¦$YEL$¨q¨r$GRN$©¦©¦$NOR$


LONG);
	setup();

	}
