inherit ROOM;
void create() {
	set( "short", "Æë¼Ò°²°ïÂ¥" );
	set( "owner", "adeyzit" );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room180",
		"up"        : "/open/clan/13_luck/room/room245",
	]) );
	set( "long", @LONG

    [0;1;5;33m¡õ[1;5mQ[1;5m¡õ[1;5mT[1;5m¡õ[1;5mN[1;5m¡õ[1;5m¡õ[0m³ÉÁ¢ÖÁ½ñ£¬°ïÎñÕôÕôÈÕÉÏ£¬Ò²ÓĞÀµ¼¸Î»Ç°ÈËµÄÅ¬Á¦°ï×¡
°ïÅÉÎÈ¹Ì£¬ÈçÌì£¬²ĞĞÄ£¬ÁÎ¹ÙÈË£¬»ì¿Ú·¹³Ô£¬¿É°®Ğ¡ÖíÍ·µÈÈË£¬Îª°ï
ÎşÉü·îÏ×£¬ÎªÁË¸ĞĞ»ÕâĞ©Ç°ÈËµÄÅ¬Á¦£¬¾Í°Ñ´ËÂ¥ÃüÃûÎªÆë¼Ò°²°ïÂ¥£¬
Ï£ÍûºóÈËÄÜ¸úËûÃÇÑ§Ï°²¢ÓĞ¹ıÖ®¶øÎŞ²»¼°¡£

LONG);
	setup();
	replace_program(ROOM);
}
