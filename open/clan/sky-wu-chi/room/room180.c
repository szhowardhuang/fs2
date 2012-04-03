inherit ROOM;
void create() {
	set( "short", "$HIB$Ğ°ÔÂÕıÌü$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room182.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room178.c",
	]) );
	set( "long", @LONG
×ßµ½Õâ,Í»È»ÄãÍ£Ö¹ÁË½Å²½,¶ÔÓÚĞ°ÔÂÕıÌü,Äã²»½ûßõßõ³ÆÆæÁËÆğÀ´
Õû¼äÕıÌüÓÃÁËĞ°ÔÂË®¾§´òÔì¶ø³É,ËùÒÔ,¸¡ÏÖ×ÅÇáÀ¶É«µÄ¹âÃ¢....
ÉÁÒ«µÄË®¾§ÕıÉÁÉÁ·¢ÁÁ×Å,Ê¹ÄãÑÛ¾¦Òò¹âÃ¢¶ø½¥½¥Ê§È¥¸Ğ¾õ,Ä£ºıÖĞ
Ö»¼û¼¸¸ö´ó×Ö....[0;1;5;34m¡õ[1;5m¡õ[1;5m~[1;5m~[1;5m~[1;5m¡õ[1;5m¡õ[1;5m~[1;5m~[1;5m~[1;5m¡õ[1;5m¡õ[1;5m~[1;5m~[1;5m~[1;5m¡õ[1;5mU[0m
LONG);
	setup();
	replace_program(ROOM);
}
