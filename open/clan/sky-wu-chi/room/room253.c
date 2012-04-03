inherit ROOM;
void create() {
	set( "short", "[1;32mÎ÷ÑÇÉñµî[0m" );
	set( "object", ([
		"file1"    : "/daemon/class/blademan/obj/ublade",
		"amount1"  : 1,
	]) );
	set( "build", 17142 );
	set( "owner", "xraistlin" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
ËùÎ½ ¶àÄ±ÕßÊ¤,ÉÙÄ±Õß°Ü ,´ËÄËÇ§¹Å²»±äÖ®ÕæÀí
Ò»¸öÓĞÓÂÎŞÄ±µÄÃ§·òÊÇÃ»ÓĞ°ì·¨ÓĞËù×÷ÎªµÄ
¾ÍÈçÍ¬Íò·òÄªµĞµÄÏîÓğ×îºóÒ²ÊÇÒªÔÚÎÚ½­×ÔØØ
Éñµû¼ÇÈ¡Ç°ÈËµÄ½ÌÑµ,¾­¹ı¼¸·¬Ë¼Á¿Ö®ºó
½¨Á¢Õâ¸öÉñµî,ÕĞ±øÂòÂí,×Ô¼ºÔòÒş²ØÓÚÄ»ºó,°µÖĞ²Ù×İ
LONG);
	setup();
	replace_program(ROOM);
}
