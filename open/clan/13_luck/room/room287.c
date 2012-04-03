inherit ROOM;
void create() {
	set( "short", "Ğ¡ÏÍ¼Ò" );
	set( "owner", "sznn" );
	set( "object", ([
		"file7"    : "/open/tendo/obj/shoe",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/open/ping/obj/neck0",
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file8"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/sky/obj1/thunder_emblem",
		"file10"   : "/open/ping/obj/gold_hand",
		"amount1"  : 1,
		"amount3"  : 62,
	]) );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room231",
	]) );
	set( "build", 10326 );
	set( "light_up", 1 );
	set( "long", @LONG

    ÄãÒ»½øµ½Õâ¸öÉñÃØ¶´Ñ¨£¬ÂíÉÏ±»ËÄµÀĞ×ºİµÄÄ¿¹âËù¾ªÏÅ£¬Ğ¡ĞÄÒ»
¿´£¬Ô­À´ÊÇËÄÖ»ÊØ»¤Ê¥ÊŞ£¬·Ö±ğÊÇ[0;1;32m¡õ[1mC[1m¡õ[1ms[0m£¬°×»¢£¬[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬[0;1;36m¡õ[1m¡õ[1m¡õ[1mZ[0mÊØ×¡¶´Ñ¨
µÄËÄÖÜ£¬Ğ¡ĞÄµÄÊØ»¤×ÅÕıÔÚÁ·¹¦µÄÖ÷ÈË£¬µ±ÄãÏë»ØÍ·Ê±£¬ÒÑ¾­Ì«ÍíÁË
£¬ËÄÖ»Ê¥ÊŞÒÑ¾­°ÑÄã°üÎ§×¡ÁË¡£


LONG);
	setup();
	replace_program(ROOM);
}
