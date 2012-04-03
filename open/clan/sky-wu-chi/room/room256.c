inherit ROOM;
void create() {
	set( "short", "Îè·ãÖ®ÎÝ" );
	set( "owner", "zsa" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 2945 );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room260.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"cong"      : "/open/clan/sky-wu-chi/room/room255",
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
