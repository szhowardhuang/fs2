inherit ROOM;
void create() {
	set( "short", "Î¬ĞŞÊÒ" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "fuze" );
	set( "build", 10207 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room94.c",
		"east"      : "/open/clan/13_luck/room/room234.c",
		"enter"     : "/open/clan/13_luck/room/room235",
		"west"      : "/open/clan/13_luck/room/room233.c",
	]) );
	set( "long", @LONG
   ÕâÀïÊÇÎ¬ĞŞ×¨¼ÒÎªÁËÔì¸£ÓĞÀ§ÄÑËù¿ª±ÙµÄÎ¬ĞŞÊÒ£¬¿´µ½·¿¼äÄÚÂúÂúµÄ¹¤¾ß
ÓëÆÆ¾ÉµÄ²ÄÁÏ£¬ÄãĞÄÏëÓĞ´ËµØ·½Î¬ĞŞÌ«ºÃÁË£¬Äã×¨×¢µÄ¿´×Å[32mÎ¬ĞŞÏÉÈË[0m£¬Å¬Á¦µÄ
ÖÆÔìÒ»Ö»Ç¿¶øÓĞÀûµÄ[31mÎäÆ÷[0m£¬ÈÃÄãĞÄ¶¯µÄÏëÇë[32mÎ¬ĞŞÏÉÈË[0m°ïÄãÖÆÔìÒ»°Ñ
  
LONG);
	setup();
	replace_program(ROOM);
}
