inherit ROOM;
void create() {
	set( "short", "$HIY$½£ĞÄµî$NOR$Ö®$HIY$ÎÊ½£ÌÃ$NOR$" );
	set( "owner", "creed" );
	set( "build", 12522 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room13.c",
		"west"      : "/open/clan/hell/room/room98",
	]) );
	set( "long", @LONG
×ß½øÎÊ½£ÌÃÖ»¼ûÒ»ÃûÉí×Å»ÒÒÂÃæ´øÓÇÈİµÄÖĞÄêÈËØùÁ¢ÔÚ
´°¿ÚËûµÄÑÛÉñ³Á×Å¶ø»úÃô£¬ÇÒÒşÒşÍ¸×Å¹âÃ¢£¬Â¶ÔÚÒÂ·şÍâµÄ
Æ¤·ô·ºÆğÒ»ÖÖÆæÒìµÄ¹âÔó£¬ÄÇÊÇ³¤ÆÚĞŞÁ·ÄÚ¼ÒÕæÆøµÄÏÖÏó£¬
ËûÕı²»ÑáÆä·³µÄ¶Ô½£×ÚµÜ×Ó½²½â×Å½£µÀµÄ°ÂÒå¡£
  ¡¸[31m»¤×Ú½£Å«[0m¡±[33m×ÏÍÀÉ±[0m(Sword guard)
  ½£×ÚµÚ¶ş´ú×ÚÖ÷ [36mĞéÈô¿Õ[0m(Master sky)

LONG);
	setup();
	replace_program(ROOM);
}
