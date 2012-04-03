inherit ROOM;
void create() {
	set( "short", "“ª“≥ ÈŒ˜œ·∑ø" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room274",
		"east"      : "/open/clan/sky-wu-chi/room/room277",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room275",
	]) );
	set( "owner", "bookman" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
    
[36m®x®z[0m                 [37m®ç®é[0m    [35m®ç[0m  [37m®ç®é[0m
 [36m®|[0m [33m®ç[0m     [36m*[0m       [30;47m®è          [35m°Ò[30m    ®ê[0m
    [33m®Ä®é[0m           [35;47m              ®è    [0m
 [36m*[0m  [33m®ê®Ä®è[0m    [36m*[0m    [35;47m              [37m®è[35m    [0m
       [36m®x®y®{®y[0m    [30;47m    °Ò        °Ò    [0m
        [36m®}®}®{[0m     [33;47m         ¶œ         [0m
                   [30;47m®é                ®ç[0m 
                     [30m®~[35;47m®}[33m®|®|®|®|[35m®}®~[30;45m®ê[0m 
                      [35;45m  [33;43m   [45m®è[35m®â®â [33m£™   [0m     [36m©n  ©n[0m
                  [36;45m®Ö[35m®â®â®â®â[33m  £™     [30m®ç[0m
                  [36;45m®Ö[33m £™           [31m®ç[0m    [36m©n   ©n[0m
                  [36;45m®Ö[33m  £™  [31m®z®{®|[40m®Ä®Ä[0m                         
                  [36;45m®Ö[31m ®z®|[46m®Ä ®Ä[33;45m*[31;46m®Ä ®Ä[0m
                         [31;46m®Ä ®Ä[33;45m*[31;46m®Ä ®Ä[0m          [36m©n   ©n[0m
                      [30;45m®y®z®|®{®}®{®y®{[0m
LONG);
	setup();
	replace_program(ROOM);
}
