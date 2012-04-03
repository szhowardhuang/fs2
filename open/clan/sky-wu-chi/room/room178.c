inherit ROOM;
void create() {
	set( "short", "$HIC$Ğ°ÔÂ»ØÀÈ$HIY$´óÃÅ$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room177.c",
		"north"     : "/open/clan/sky-wu-chi/room/room180",
	]) );
	set( "long", @LONG
×ß½øÕâÀï,±ã¼ûÒ»×ùÏãÑÌôÁôÁµÄ´óÏãÂ¯×øÂäÓÚ¹ã´óµÄ´óÌüÖ®ÖĞ
Â¯ÄÚÆ®³öÁËÒ»ÕóÕóÈÃÄã¾«ÉñÆøË¬µÄ°×ÑÌ,Ê¹Äã¾ªÑÈµÄÊÇ,Ô­À´ÕâÊÇ
ÌìµÀÎŞ¼«°ïÖ÷~~~[0;1;36m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1mJ[0mÒÔÄÚÁ¦Ëù¼¤·¢³öÀ´µÄ...........
LONG);
	setup();
	replace_program(ROOM);
}
