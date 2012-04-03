inherit ROOM;
void create() {
	set( "short", "¿ÒŒÔ∑ø" );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/dancer/obj/yuawaist",
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/daemon/class/fighter/ywhand",
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"amount8"  : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "owner", "diana" );
	set( "build", 10055 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room235",
		"south"     : "/open/clan/sky-wu-chi/room/room214.c",
		"west"      : "/open/clan/sky-wu-chi/room/room236",
	]) );
	set( "long", @LONG
 ®q©–©§©§©–©§©§®r       °Ô         ®q©§    £Æ   ©§©‡©§®r  ®q®s    °Ò    ®q®s
   ©¿©§©§©»  ®q©ÿ©§®r ©§©§©§     ®q©»    ©¶©¶©¶   ©¶  ©¶®q®s®q  ®q©§®r®q®s®q
   ©¿©§©§©»  ©¶    ©¶   ©§   ©§®r®s©¶®q®r©¶©¶©¶   ©¶  ©¶®t©§©»  ®b®T®e®t©§©»
 ©§©ÿ©§©§©‡©§®t©§©§®s   ©§   ®q®s  ©¶®t®s©¶©¶©¶   ©¶  ©¶  ®q®s  ©¶  ©¶  ®q®s
  £Æ        ®q©§©§®r ®q©§©§®r®t®r©¶©¶    ©¶©¶©¶ ©§©‡©§©ÿ©§®t©§®s®t©§®s  ®t©§®s
    ®q©§©§©–®s®q©§®r ©¶    ©¶®q®s©¶©¶    ©¶©¶©¶   ©¶      ©§©§©§©§©‡©§©§©§©§
®t©§®s©§©§©‡©§®s     ©¶    ©¶©¿®r©ÿ©ÿ©§  ®t©‡®s ®q®s®t®r    ®q®s  ©¶  ®t®r®r
£Æ©§©§©§©§©ÿ©§©§©§£Æ ®t©§©§®s®s®t©§©§©§©§  ©¶ ®q®s    ®t®r®t®s  ®t®s    ®t®s
                             °Ó                                     £Æ
    °Ô    °Ô         °ı            £Æ        °Ô    °Ô        - °Ô -     °Ô
                    °ı°ı       £Æ        °Ô                  ®ç®Ä®é
   °Ó     °Ô       °ı°ı°ı°ı                 £Æ        £Æ    ®ç®Ä®Ä®é       £Æ
                °ı°ı°ı°ı°ı°ı      ©‡         £Æ            ®ç®Ä®Ä£Æ®é
               °ı°ı°ı°ı°ı°ı°ı     ©¶___________           ®ç®Ä£Æ®Ä®Ä®é  £Æ
       °ı     °ı°ı°ı°ı°ı°ı°ı°ı   ®ç®é®ê®Ä®Ä®Ä®Ä®é        ®ç®Ä®Ä®Ä®~®Ä®é   £Æ
      °ı°ı    *°ı°ı°ı°ı°ı°ı°ı  ®ç®Ä®Ä®é®ê®~®Ä®~®Ä®é     ®ç®Ä°Ô®Ä°®Ä®~®é
     °ı°ı°ı   °ı°ı°ı°ı°ı°ı°ı ®ç®Ä®Ä®Ä®Ä®é®ê®~®Ä®~®Ä®é  ®ç®~®Ä®Ä®Ä®~®~®Ä®é£Æ
    °ı°ı°ı°ı   °ı°ı°ı°ı°ı°ı°ı  ®Ä®è®ê®Ä           |   ®ç®Ä®Ä®~®~®Ä£Æ®Ä®~®é
 ®x®x®z®{®z®y®x®x®y®y¢Û®z®{®|®~®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®Ä®~®~®}®Ä®~®}®Ä®Ä®Ä®Ä
LONG);
	setup();
	replace_program(ROOM);
}
