inherit ROOM;
void create() {
	set( "short", "¿¡≥ÊŸ∏" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/capital/obj/blade2",
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount10" : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/gsword/obj/yuskirt",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/capital/room/king/obj/dagger1",
		"amount4"  : 1,
	]) );
	set( "build", 10177 );
	set( "light_up", 1 );
	set( "owner", "scs" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room166",
	]) );
	set( "long", @LONG
           ®z®{®|                                                          
               £¸°‘©¶
               ©¶®x®y
               ®Ö   ®Ö
                     
  ®{®|®}             
  ®x®y®z                                      ¶‰  ¶‰
®y ®x    ®x®y                         ¶‰ ¶‰®ç      ®é¶‰ ¶‰
        ®M®y®y                   ¶‰¶‰®ç     ®é      ®è     ®é¶‰¶‰
®~®~®~®~®Ö= =                  ®ç    ®é  ®â ®è ®}®} ®ê  ®â ®è    ®é
 | | |  ®Ö= =                  ®ê®}®}®è         °         ®ê®}®}®è¶‰
 | | |  ®Ö= =    ®y  ®á    ©¶©¶®{®}®}®|®ç ®y                         ®é     ®y
®y®|®|®}®Ö                ®{           ®é ®{ ®z®{®{®~        ®é      ®è        
    ®y®y  ®~®y®y®~®}®y®y®y                     ®|®|            ®é®x®x°ˆ°ˆ°ˆ°ˆ°ˆ
    ©§©§®y®z©§©§®z®{©§©§©§                                       ®ç®é®{®{      
®~®z®|®~           ®}®{®y              ®y®y®{              ®}®{®y  ®y®y®{®{®}®}
                           ®{®{®{®}           
  ®~®~®~®~®}®}®}®}®|®|®|®| ®{®{®z®z®y®y®x®x     ®x®x®y®y®z®z®{®{®|®|®|®}®}®~®~ 
           ®{®{®{®{®{®{®{®z                  ®}                                
         ®ç®è  ®Ñ ®ê®é\®x®x®é_                                                 
         ®z®|®y  ®y ®~®}®|®z  ®}®|®{                             
LONG);
	setup();
	replace_program(ROOM);
}
