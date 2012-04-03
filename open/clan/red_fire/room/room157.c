inherit ROOM;
void create() {
	set( "short", "$HIC$¡¾$HIW$»¨¸ÚÑÒ $GRN$Ê¯½×$HIC$¡¿$NOR$" );
	set( "outdoors", "/open/clan/red_fire" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/red_fire/room/room16.c",
		"up"        : "/open/clan/red_fire/room/room14",
	]) );
	set( "long", @LONG
    
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
	replace_program(ROOM);
}
