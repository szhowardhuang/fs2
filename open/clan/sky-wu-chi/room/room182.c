inherit ROOM;
void create() {
	set( "short", "$HIC$Ğ°ÔÂ»ØÀÈ$NOR$" );
	set( "build", 66 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room181.c",
		"west"      : "/open/clan/sky-wu-chi/room/room185.c",
		"south"     : "/open/clan/sky-wu-chi/room/room180",
	]) );
	set( "long", @LONG
×ß½øÕâÀï,±ã¼ûÒ»×ùÏãÑÌôÁôÁµÄ´óÏãÂ¯×øÂäÓÚ¹ã´óµÄ´óÌüÖ®ÖĞ
Â¯ÄÚÆ®³öÁËÒ»ÕóÕóÈÃÄã¾«ÉñÆøË¬µÄ°×ÑÌ,Ê¹Äã¾ªÑÈµÄÊÇ,Ô­À´ÕâÊÇ
ÌìµÀÎŞ¼«°ïÖ÷~~~[0;1;36m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1mJ[0mÒÔÄÚÁ¦Ëù¼¤·¢³öÀ´µÄ...........

<----[0;1;33m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1mB[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mp[1m¡õ[1mM[1m¡õ[1m¡õ[1m [1m [1m [1m¡õ[1mL[1m¡õ[1mp[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m---->
LONG);
	setup();
	replace_program(ROOM);
}
