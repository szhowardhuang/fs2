inherit ROOM;
void create() {
	set( "short", "[1;37mÉä»÷Ö¸»ÓËù[0m" );
	set( "owner", "really" );
	set( "object", ([
		"amount4"  : 11,
		"file7"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"amount2"  : 4,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 1,
		"amount3"  : 3,
		"file10"   : "/open/main/obj/et_sword",
		"amount5"  : 1,
		"file9"    : "/daemon/class/fighter/ywboots",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/daemon/class/fighter/ywhand",
		"file2"    : "/open/fire-hole/obj/y-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 1,
		"amount10" : 1,
		"amount1"  : 4,
	]) );
	set( "light_up", 1 );
	set( "build", 10189 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room244.c",
		"down"      : "/open/clan/ou-cloud-club/room/room298",
	]) );
	set( "long", @LONG
ÕâÀïÊÇÒ»Æ¬¿Õ¿õµÄ²İÔ­£¬ÂÌÓÍÓÍµÄÒ»Æ¬ÈÃÈË¿´ÁËĞÄ¿õÉñ
âù£¬ÕıÇ°·½²»Ô¶´¦ÓĞÒ»¿ÅÆß³ß¸ßµÄ´óÊ÷£¬Ê÷ÏÂÓĞ¼¸¸öÈËÕıÎ§
ÔÚÒ»ÕÅĞ¡Ğ¡µÄ×À×ÓÅÔ±ß£¬Äã×ß½üÒ»¿´£¬·¢ÏÖ×ÀÉÏ·Å×ÅÒ»ÕÅ·½
ÑÛÖ½£¬ÉÏÃæ»­ÂúÁËÄã¿´²»¶®µÃ¼ÇºÅ£¬ÉíÅÔÈı³ß´¦ÓĞÒ»¸öÈËÕı
¶Ô×ÅÓĞÏßµçµÄ»°Í²º°×Å£º[1;33m¡®È«ÅÅ¡¢Áñµ¯¡¢£ÁÅúºÅ¡¢ÎåºÅ×°Ò©
¡¢Ë²·¢ĞÅ¹Ü¡¯[0m£¬¼¸ÃëÖÓÒÔºóÌıÍ²Ò²´«À´¸´ËĞµÄÉùÒô¡£
  
  [1;36mÉä»÷Ö¸»ÓËù×é³¤[0m(Mortar leader)
[1;32m  Éä»÷Ö¸»ÓËù×éÔ±[0m(Mortar man1-2)[0m
LONG);
	setup();
	replace_program(ROOM);
}
