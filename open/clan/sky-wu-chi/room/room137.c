inherit ROOM;
void create() {
	set( "short", "´µÑ©Ö®ËÉĞ¡¾¶" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 95,
		"amount7"  : 171,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 38,
		"amount3"  : 16,
		"amount5"  : 15,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 200,
		"file3"    : "/open/fire-hole/obj/y-pill",
		"amount9"  : 400,
		"file1"    : "/open/fire-hole/obj/p-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 88,
		"amount2"  : 312,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/doctor/pill/human_pill",
		"amount8"  : 380,
		"file9"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 12120 );
	set( "owner", "ywarter" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room117",
		"enter"     : "/open/clan/sky-wu-chi/room/room136.c",
		"out"       : "/open/clan/sky-wu-chi/room/room151.c",
	]) );
	set( "long", @LONG
×ß½øÁË[1;37m¡®[1;34m°ÔÆøÌÃ[1;37m¡¯[0mºó£¬ÄãÀ´µ½ÁËÍ¨Íù¿ÕÆ¿×ÓÎÔÊÒµÄ»ØÂ·Ğ¡¾¶ÉÏ
ÕâÀïÆøÎÂ¿ªÊ¼ÏÂ½µ£¬¿ÉÄÜÊÇ¿ÕÆ¿×ÓµÄ¾ÓËùÊÇÒÀÉ½¶ø½¨µÄ£¬ËùÒÔÒ²¾Í
ÍùÀïÃæ×ßµÈÓÚÊÇÍùÉ½ÉÏ×ßÁËÉÏÈ¥¡£ÆøÎÂÒ²Ô½À´Ô½µÍ£¬Á½ÅÔµÄËÉÊ÷ÉÏ
¶¼Õ´ÂúÁËºñºñµÄÑ©»¨£¬ËÄÖÜ¾°É«Ò²¿ªÊ¼±ä³ÉÒ»Æ¬µÄÑ©°×É«¡£´ËÊ±Äã
ÒÑÓÃÇá¹¦±¼×ßÁË¿ìÈıÀïµÄÂ·³Ì£¬µ«ÊÇ¾ÍÊÇ»¹Ã»µ½¿ÕÆ¿×Ó¾ÓµÄºóÔº£¬
ÑÛÖĞ¿ªÊ¼ÒòÑ©»¨Æ®Æ®ÂäÏÂ¶øÄ£ºıÆğÀ´¡£

LONG);
	setup();
	replace_program(ROOM);
}
