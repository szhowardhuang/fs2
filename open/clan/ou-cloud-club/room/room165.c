inherit ROOM;
void create() {
	set( "short", "ÃÎ»Ã¸ó" );
	set( "light_up", 1 );
	set( "build", 60 );
	set( "object", ([
		"amount6"  : 1,
		"file8"    : "/open/dancer/obj/maple_ribbon",
		"file5"    : "/open/prayer/obj/boris-hands",
		"amount4"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/prayer/obj/boris-hat",
		"file3"    : "/open/prayer/obj/boris-cloth",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/open/dancer/obj/yuaboots",
	]) );
	set( "owner", "ads" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room164",
	]) );
	set( "long", @LONG

                  [33mÃÎ»Ã¸ó [0m     

      ÕâÀïÊÇÒ¹ÃÎĞ¡ÖşµÄ´óµî[0;1;36m¡õ[1mm[0;33mÃÎ»Ã¸ó[0;1;36m¡õ[1mn[0m£¬ÕâÀïÊÇ[31m»ÃÄ§[0m
  µÜ×ÓÃÇÆ½³£Ñ§Ï°Îèµ¸¡¢ÎäÊõµÄµØ·½£¬½¨ÖşµÃÃÀÂØÃÀ»À£¬
  ÃÀÀöµÄ½¨ÖşÔÙ¼ÓÉÏÎèÕßÃÇÓÅÃÀµÄÎèµ¸£¬ÕæÊÇ»áÁîÈËÒÔÎª
  Éí´¦»Ã¾³¡£

LONG);
	setup();
	replace_program(ROOM);
}
