inherit ROOM;
void create() {
	set( "short", "[1;31mĞ°£®ĞÄ£®½ç[0m" );
	set( "owner", "rings" );
	set( "object", ([
		"file2"    : "/open/capital/guard/gring",
		"amount9"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/daemon/class/blademan/obj/ublade",
		"amount5"  : 1,
		"file8"    : "/open/main/obj/shiblade",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file5"    : "/daemon/class/blademan/obj/iceblade",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire_book",
		"amount4"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
	]) );
	set( "build", 11076 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room230",
	]) );
	set( "long", @LONG
ÑØ×ÅĞ¡¾¶»º»ºÇ°½ø£¬À´µ½ÁËÒ»¼ä¿Õ¼ä¹ãÀ«µÄÊ¯ÊÒ£¬¹âÏß
ÊÇ´Ó½ÏÎªÉÏ²ãµÄÊ¯±ÚÍ¸¹â¶øÀ´£¬Ê¯ÊÒµÄÕıÖĞÑë·Å×ÅÒ»¸öÁğÁ§
×ù£¬ÉÏÃæ·Å×ÅÒ»°ÑË®À¶É«µÄµ¶£¬ÒşÒş·º×ÅÓÕÈËµÄÀ¶¹â£¬µ±Äã
½Ó½üµÄÊ±ºòÍ»È»¸Ğ¾õµ½Ò»¹ÉÑıÆøÔÚ¿ÕÆøÖĞÃÖÂş£¬ËÄÖÜµÄÉùÒô
·Â·ğ¶¼±»ÔÚÒ»Ë²¼ä±»³é¿Õ£¬Ö»ÓĞÄãµÄĞÄÌøÉùÒÀÈ»ÆËÍ¨¡¢ÆËÍ¨
µÄÔÚ¶ú±ßÎ§ÈÆ¡£
  
LONG);
	setup();
	replace_program(ROOM);
}
