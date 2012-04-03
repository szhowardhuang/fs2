inherit ROOM;
void create() {
	set( "short", "$HIB$¡¾$HIC$Ê¥  Ê¯  ±®$HIB$¡¿$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"D"         : "/open/clan/sky-wu-chi/room/room91.c",
		"Y"         : "/open/clan/sky-wu-chi/room/room60.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"Q"         : "/open/clan/sky-wu-chi/room/room48.c",
		"V"         : "/open/clan/sky-wu-chi/room/room64.c",
		"B"         : "/open/clan/sky-wu-chi/room/room19.c",
		"O"         : "/open/clan/sky-wu-chi/room/room93",
		"F"         : "/open/clan/sky-wu-chi/room/room34.c",
		"U"         : "/open/clan/sky-wu-chi/room/room65.c",
		"W"         : "/open/clan/sky-wu-chi/room/room63.c",
		"N"         : "/open/clan/sky-wu-chi/room/room47.c",
		"R"         : "/open/clan/sky-wu-chi/room/room37.c",
		"L"         : "/open/clan/sky-wu-chi/room/room55.c",
		"X"         : "/open/clan/sky-wu-chi/room/room62.c",
		"J"         : "/open/clan/sky-wu-chi/room/room58.c",
		"S"         : "/open/clan/sky-wu-chi/room/room36.c",
		"H"         : "/open/clan/sky-wu-chi/room/room26.c",
		"E"         : "/open/clan/sky-wu-chi/room/room29.c",
		"I"         : "/open/clan/sky-wu-chi/room/room92.c",
		"M"         : "/open/clan/sky-wu-chi/room/room51.c",
		"P"         : "/open/clan/sky-wu-chi/room/room43.c",
		"C"         : "/open/clan/sky-wu-chi/room/room35.c",
		"Z"         : "/open/clan/sky-wu-chi/room/room71.c",
		"G"         : "/open/clan/sky-wu-chi/room/room28.c",
		"K"         : "/open/clan/sky-wu-chi/room/room57.c",
		"T"         : "/open/clan/sky-wu-chi/room/room68.c",
		"A"         : "/open/clan/sky-wu-chi/room/room13.c",
	]) );
	set( "long", @LONG
Ïà´«,ÉÏ¹ÅÊ±´ú,ÒòÎªÌìÉÏµÄ×÷ÂÒÈË¼ä,µ¼ÖÂÃñ²»ÁÄÉú,±ø»ÄÂíÂÒ,
ÕâÊ±ÓĞ¶şÊ®ÁùÎ»[0;1;34m¡õ[1mj[1m¡õ[1mt[1m¡õ[1m¡õ[0mÎªÁËµÖ¿¹ÌìÉñµÄ×÷Åª,·Ü¶øÈºÆğµÖ¿¹,ÔÚ
Ò»Î»ÓµÓĞÑıµ¶µÄĞ°ÑàÁìµ¼ÏÂ,¸úÖîÎ»ÌìÉñ´óÕ½,µ«»¹ÊÇ²»µĞÌìÉÏ
µÄÖîÉñÕâÊ±ÖÚ¹ÅÊ¥Õß¾ö¶¨~~ÒÔÎşÉü×ÔÎÒ,»¹»»È¡¿ñÏë¿Õ¼äµÄºÍÆ½,
ÔÚ¶şÊ®ÁùµÀ·É¹ıÌì¼ÊÊ±,ÌìÉÏÖÚÉñ±»ÖØ´´ÁË...µ«¹ÅÊ¥ÕßÒ²Òò·Å³ö
±ÏÉúµÄ¹¦Á¦Ê¹ËûÃÇ»¯Îª»Ò½ı...ÔÚĞ°ÑàµÄ´«ÈË<[0;1;36m¡õ[1mM[1m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1mJ[0m>µÄ±¼×ßÏÂ
ÖÕÓÚÊÕ¼¯µ½ÁË¶şÊ®ÁùÎ»¹ÅÊ¥ÕßµÄÒÅº¡....²¢ÇÒÓÃ±ÏÉúËùÑ§,»¯³ÉÁË
¶şÊ®Áù¿Å´«ËÍÊ¯...Ö»ÒªÄã³ÏĞÄºô»½Ê¥ÕßÖ®Ãû...Äã±ã¿ÉÒÔ´«ËÍµ½
[0;1;33m¡õ[1mt[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÈ¥ÁË....                                ĞÀ
LONG);
	setup();
	replace_program(ROOM);
}
