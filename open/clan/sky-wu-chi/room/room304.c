inherit ROOM;
void create() {
	set( "short", "$HIR$Ÿ´$HIC$‘∆$HIW$æ”" );
	set( "owner", "mudu" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/gsword/npc2/sadsword",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file1"    : "/u/b/babe/cloud",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/gsword/obj/silver_sword",
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/badman/obj/sword_book",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/capital/guard/gring",
		"amount7"  : 1,
		"amount10" : 1,
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
	]) );
	set( "build", 10104 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
                                                                                   
         °Ò---                                   ¶Â                             
         £¸£‹                                 ¶Â     ¶Â                         
                  ®ç®Ä®Ä®Ä®Ä®Ä®è®ê®Ä                      ®ç®é                  
    ®x®y®{®x®z®y®ç®Ä®Ä®Ä®Ä®Ä®è ®í ®ê®y®z®z®y®{®}®|®z®y®{ ®ç®Ä®é®y               
    ®y®z®x®z®{®|®áÃÔ ÃÔ ÃÔ®ä========®x®y®z®x®y®x®ç®é®z®x®ç®Ä®Ä®é®x              
              ®ç®Ä®Ä®Ä®Ä®Ä®è ®ä®ê®Ä®Ä®é        ®ç®Ä®é   ®ç®Ä®Ä®é                
              ®áÃÔ ®Ä ÃÔ®ä   ®ä®ä  ÃÔ          ®ç®Ä®é  ®ç®Ä®Ä®Ä®é               
      ®ts©–©–®á   ®Ä   ®ä   ®ä®ä      ©–©–©–©–©–®Ä©–©–©–  ®Ä                   
    ®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â®â              


LONG);
	setup();
	replace_program(ROOM);
}
