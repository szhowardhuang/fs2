inherit ROOM;
void create() {
	set( "short", "Ó¢»êÊ¥µî" );
	set( "owner", "dracula" );
	set( "item_desc", ([
		"crystal" : @ITEM
»ëÌì±¦¼ø²©´ó¾«Éî, ×Ü¹²Ê®²ã, ÒÀĞòÎª:

[0;1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[35mÃµÏ¼µ´[0m
[33mÍÁÀ¥ÂØ[0m
[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mB[0m
[0;1;35m¡õ[1m¡õ[1m¡õ[1mP[1m¡õ[1me[0m
Ğş»ìãç
[0;1;34m¡õ[1mQ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mf[0m
[0;1;31m¡õ[1m¡õ[1m¡õ[1ma[1m¡õ[1m¡õ[0m
[0;1;30m¡õ[1m¡õ[1m¡õ[1mt[1m¡õ[1mz[0m

ITEM,
	]) );
	set( "object", ([
		"file4"    : "/open/capital/guard/gring",
		"file6"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount7"  : 1,
		"amount2"  : 262,
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/dancer/obj/linrboots",
		"file9"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10120 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room87",
	]) );
	set( "long", @LONG
¿ÕÆøÖĞÆ®×ÅÅ¨ÁÒµÄÓÇÓôÆøÏ¢, ·Â·ğ¸ĞÌ¾Ó¢ĞÛÆø¶Ì, ÊÀÍ¾¶à¼è, ´ËµØÔ­ÊÇÒ»Î»
ÎŞÃûÓ¢ĞÛ³ÉÃûÇ°µÄĞŞĞĞÖ®µØ, ÔÚÕâ¸öÓ¢ĞÛÎªÁËµÖÓùÍâ×å¶øÒãÈ»Ì¤ÈëÄ§µÀ, ÉõÖÁ
ÊÜµ½ÕıµÀÈºĞÛÎ§½Ë¶øÊ§×ÙÖ®ºó, ±»Ğí¶àÎó½âËûµÄÈËËù´İ»Ù, Ö±µ½¶àÄêºó, ÖÚÈËË¼
¼°Ëûµ±ÈÕ¾öÕ½ÉñÃØÍâ×åµÄ¸°ËÀÉñÍşÊ±, ²Å¿ªÊ¼×ğ¾´Õâ¸öÏÂÂä²»Ã÷µÄÓ¢ĞÛ, Òò´Ë,
½«Ëû¹Ê¾ÓÖØĞÂ½¨Á¢ÆğÀ´, ²¢¼ÀÆğ´ú±íÆäÁ÷ÅÉ, ÓÀ²»Ï¨ÃğµÄĞÜĞÜÊ¥»ğ, ÒÔ±íÊ¾ÆÚÅÎ
Ëû¹éÀ´, ¼ÌĞøÍ³ÁìÈºÂ×µÄÒ»Ìì, ÍùÊ¥»ğ×îÖÄÊ¢µÄÖĞĞÄµãÍûÈ¥, ÒÀÏ¡¿É¿´µ½²åÂúÁË
»ëÌì±¦¼øÊ®Ìì¾§(crystal)µÄÌìÌ³

    [0;1;33m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m_[1m¡õ[1m¡õ[1;37m¡õ[1m¡õ[1m¡õ[1m\[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m(crystal)
LONG);
	setup();
	replace_program(ROOM);
}
