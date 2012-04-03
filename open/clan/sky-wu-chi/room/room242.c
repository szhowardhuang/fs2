inherit ROOM;
void create() {
	set( "short", "Ã¨·¿" );
	set( "owner", "timekiller" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room95.c",
		"east"      : "/open/clan/sky-wu-chi/room/room225.c",
		"north"     : "/open/clan/sky-wu-chi/room/room224.c",
		"out"       : "/open/clan/sky-wu-chi/room/room120.c",
		"west"      : "/open/clan/sky-wu-chi/room/room223.c",
	]) );
	set( "long", @LONG
            ,,                                ;'
           ';;                         ;  ,,;;;'
            ;;             ,,;;;'  ,,, ;   ,;
            ;;           ,    ;'   ';  ; ,'
            ;;           ;   ,;,,      ,;'
            ;;      ',,  ;,  ;;'      '  ,,,;';,
  ,,,;'     ;;       ';;             ,;'';     ;'
 ;;;'      ,;;                      ;  ,,;;;  ;;
 ''       ';;;                      ;,' ;;    ;'
                                      ,,;;;,,,;
                                             '
LONG);
	setup();
	replace_program(ROOM);
}
