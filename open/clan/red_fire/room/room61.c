inherit ROOM;
void create() {
	set( "short", "$HIC$¡¾$HIR$ºìÁ« $HIM$´ó·¹µê$HIC$¡¿$NOR$" );
	set( "outdoors", "/open/clan/red_fire" );
	set( "light_up", 1 );
	set( "build", 10127 );
	set( "exits", ([
		"north"     : "/open/clan/red_fire/room/room32",
		"hotel"     : "/open/clan/red_fire/room/room70.c",
		"south"     : "/open/clan/red_fire/room/room31.c",
	]) );
	set( "long", @LONG
 
                    $HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ
                    $HIC$¡Ñ  $HIR$ºì   Á«   $HIM$´ó   ·¹   µê  $HIR$¡Ñ
                    $HIG$¡Ñ                          $HIY$¡Ñ
                    $HIC$¡Ñ  $HIR$Red_Fire  $HIM$H  O  T  E  L $HIG$¡Ñ
                    $HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ$HIG$¡Ñ$HIY$¡Ñ$HIC$¡Ñ$HIR$¡Ñ
                            $HIW$¨¨¡õ    ¨¨     
                      $HIY$¡ø$HIM$¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö$HIY$¡ø
                      $HIM$¡ö¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö¡ö
                      ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
                      ¡ö¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö¡ö
                    $HIY$¡ø$HIM$¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö$HIY$¡ø
                    $HIM$¡ö¡ö¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö¡ö¡ö
                    ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
                    ¡ö¡ö¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö¡ö¡ö
                    ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
     $HIR$¨¡õ¨¡õ¨  ¨$HIM$ ¡ö¡ö¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö$HIC$¡ö$HIM$¡ö¡ö¡ö $HIR$¨  ¨  ¨  ¨
    $HIB$¨’  ¨’  ¨’  ¨’ $HIM$ ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö  $HIB$¨’  ¨’  ¨’  ¨’
    $HIW$¨U  ¨U  ¨U  ¨U $HIM$ ¡ö    ¡ö      ¡ö      ¡ö    ¡ö  $HIW$¨U  ¨U  ¨U  ¨U
    $HIW$¨U  ¨U  ¨U  ¨U $HIM$ ¡ö    ¡ö      ¡ö      ¡ö    ¡ö  $HIW$¨U  ¨U  ¨U  ¨U
    $HIW$¨U  ¨U  ¨U  ¨U $HIM$ ¡ö    ¡ö      ¡ö      ¡ö    ¡ö  $HIW$¨U  ¨U  ¨U  ¨U
    $HIW$¨U  ¨U  ¨U  ¨U $HIM$ ¡ö    ¡ö      ¡ö      ¡ö    ¡ö  $HIW$¨U  ¨U  ¨U  ¨U
    $HIC$¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰¨‰$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
