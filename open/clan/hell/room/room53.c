inherit ROOM;
void create() {
	set( "short", "$HIW$ºÚÂÖÎÔ·¿ - $HIC$Ö÷ÊÒ$NOR$" );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount8"  : 3,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 20,
	]) );
	set( "build", 10073 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room40",
		"north"     : "/open/clan/hell/room/room40",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÕâÀï¾ÍÊÇºÚÂÖÎÔÊÒµÄÖ÷·¿ÁË£¬ÑÛÇ°ÕâÎ»±ãÊÇ´«Ëµ
ËµÖĞµÄ½£Ä§£®  ËûÕıÔÚ±ÕÄ¿ÑøÉñ£®¼´Ê¹Èç´ËÉíÉÏ»¹ÊÇ
Á÷³ö¾ªÈËµÄÉ±ìåÖ®Æø£¬Äã²»ÓÉµÄÍËºóÁË¼¸²½£¬ÉîÅÂ¾ª
ĞÑÁËÕâÎ»  [0;1;32m¡õ[1mC[1;34m [1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[1m [1;31m¡õ[1m][0m [0;1m¡õ[1mE[0m [0;1m¡õ[1m¡õ[1m [1m¡õ[1m¡õ[0m

([0;1;31m¡õ[1m¡õ[1m¡õ[1mN[1;36m¡õ[1mg[1m¡õ[1m¡õ[0m)[0;1;31m¡õ[1mC[1m¡õ[1m][0m¡¸[0;1m¡õ[1m¡õ[1;31m¡õ[1m¡õ[1;37m¡õ[1mC[0m¡±ºÚÂÖ(Jinkazama)

LONG);
	setup();
	replace_program(ROOM);
}
