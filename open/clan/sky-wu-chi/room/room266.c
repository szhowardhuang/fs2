inherit ROOM;
void create() {
	set( "short", "Á·¹¦·¿" );
	set( "owner", "cong" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room261",
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
