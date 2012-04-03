inherit ROOM;
void create() {
	set( "short", "$HIW$Õı$HIG$£®$HIR$Ğ°$HIG$£®$HIB$µÀ$NOR$" );
	set( "owner", "rings" );
	set( "item_desc", ([
		"words" : @ITEM
    
    [1;37mÕı    [1;31mĞ°    [1;34mÁ½    [1;33,[1;33m²»    [1;32m·Ö[0m
      
ITEM,
	]) );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 10049 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room232",
		"enter"     : "/open/clan/ou-cloud-club/room/room220.c",
		"up"        : "/open/clan/ou-cloud-club/room/room229",
	]) );
	set( "long", @LONG
ÑØ×ÅĞ¡¾¶»º»ºÇ°½ø£¬À´µ½ÁËÒ»¼ä¿Õ¼ä¹ãÀ«µÄÊ¯ÊÒ£¬¹âÏß
ÊÇ´Ó½ÏÎªÉÏ²ãµÄÊ¯±ÚÍ¸¹â¶øÀ´£¬ÑöÍ·ÍûÈ¥£¬ÓĞÒ»×ùĞü¿ÕµÄÆ½
Ì¨£¬¿¿×ÅÊ®ÁùÌõÊÖÍó°ã´ÖµÄÌúÁ´ÓëÖÜÎ§µÄÇ½±ÚÁ¬½á£¬ÌúÁ´ÉÏ
²¼ÂúÁËÊıÒÔÍò¼ÆµÄÖ©Öë£¬Æ½Ì¨ÉÏÓĞÒ»¿éĞ¡Ê¯±®£¬ÉÏÃæ¿Ì×Å¼¸
¸ö´ó×Ö(words) £¬Ê¯±®ÖÜÎ§ÓĞ¼¸°Ñ±øÆ÷ÒşÒş·º×Å½ğ¹â¡£
  
LONG);
	setup();
	replace_program(ROOM);
}
