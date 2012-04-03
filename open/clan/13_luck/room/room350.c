inherit ROOM;
void create() {
	set( "short", "Ğ°µ¶ÊÒ" );
	set( "owner", "max" );
	set( "object", ([
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"file1"    : "/open/main/obj/shiblade",
		"amount2"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount7"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room352",
	]) );
	set( "long", @LONG

    Ò»½øÈë´ËÊÒÖĞ£¬Ö»¼ûÇ½ÉÏ¹Ò×ÅÒ»°Ñ [0;1;35m¡õ[1m¡õ[1m¡õ[1mM[0m(Shi-blade)£¬µ¶ÉÏ¿Ì×ÅÒ»Ğ©
Ï¸Ï¸Ğ¡Ğ¡µÄ×Ö£¬×ĞÏ¸¿´È¥Ô­À´ÊÇÄ§µ¶¡®ÈıÕ¶¹éÔª¡¯µ¶·¨Ö®Ò»£¬Š…¾Û¼¯¾ÅÌì
Ö®Æø£¬Ê¹³ö[35m¡¾ÈıÕ¶¹éÔª¡«Ğ°ÁúÕ¶Ôª¡¿[0m¡®Ä§[0;1;36m¡õ[1ms[1;33m¡õ[1m¡õ[1;36m¡õ[1m¡õ[0m¡«¡«[0;1;31m¡õ[1mI[0mÌì[0;1;34m¡õ[1m¡õ[1;36m¡õ[1m¡õ[0m¡¯£¬»Ê¹¬½û
ÎÀ¾ü¾ªãµÖ®ÓÚ£¬Ö»¼ûŠ…°Ñ[0;1;35m¡õ[1m¡õ[1m¡õ[1mM[0m²åÓÚµØÉÏ£¬†ˆÆğÃØÖä£¬Ë²Ê±»ğÑæš\ÕÅÑÍÂşÕû
¸öÌì¼Ê¡£

LONG);
	setup();
	replace_program(ROOM);
}
