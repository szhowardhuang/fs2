inherit ROOM;
void create() {
	set( "short", "ÐÂÇøÓò" );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "owner", "sogo" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room316",
	]) );
	set( "long", @LONG

     ¡ø=================================================================¡ø
     ¨‚¨‡                                                   ¨          ¨‚¨‡
     ¨‚¨‡ ¨¨¨¨¨¨¨                        ¨¨   ¨¨¨¨¨¨     ¨‚¨‡
     ¨‚¨‡    ¨       ¨                                 ¨     ¨      ¨‚¨‡
     ¨‚¨‡    ¨       ¨    ¨¨¨¨¨¨¨¨    ¨¨  ¨¨¨¨¨¨¨    ¨‚¨‡
     ¨‚¨‡   ¨        ¨                          ¨    ¨  ¨  ¨      ¨‚¨‡
     ¨‚¨‡   ¨        ¨                         ¨     ¨  ¨  ¨      ¨‚¨‡
     ¨‚¨‡   ¨  ¨¨¨¨                        ¨     ¨   ¨  ¨¨    ¨‚¨‡
     ¨‚¨‡                                                               ¨‚¨‡
  ¨t¨€¨€¨s===========================================================¨t¨€¨€¨s
     ¡ñ                                                                 ¡ñ
     ¡ñ                                                                 ¡ñ



LONG);
	setup();
	replace_program(ROOM);
}
