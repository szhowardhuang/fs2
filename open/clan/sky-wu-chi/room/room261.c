inherit ROOM;
void create() {
	set( "short", "œ° ¿’‰±¶ ’≤ÿ “" );
	set( "owner", "cong" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room268.c",
		"up"        : "/open/clan/sky-wu-chi/room/room99.c",
		"north"     : "/open/clan/sky-wu-chi/room/room266.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
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
