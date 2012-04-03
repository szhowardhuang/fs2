inherit ROOM;
void create() {
	set( "short", "°Ù²İµÀ" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/capital/obj/chen_dagger",
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/ping/obj/ring-2",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/killer/obj/s_pill",
		"amount5"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
	]) );
	set( "build", 11610 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room337",
		"north"     : "/open/clan/13_luck/room/room339.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÄãÍ»È»ÑÛÇ°Ò»ÁÁ£¬¼û[0;1;32m¡õ[1mC[1m¡õ[1mC[1m¡õ[1mA[1m¡õ[1m¡õ[0m£¬Âúµã×º×Å»ò[0;1;31m¡õ[1m¡õ[0m»ò[45m×Ï[0m£¬»ò[0;1;33m¡õ[1m¡õ[0m»ò[0;1m¡õ[1m¡õ[0mµÄ
ÏÊ»¨¡£ÄãÒ»Â·ĞĞÀ´£¬±éµØ¶¼ÊÇ[0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬´Ë´¦¾¹ÊÇÒ»¸ö»¨»¨ÀöÀöµÄÊÀ
½ç£¬ÄãÔÚ´Ë´¦£¬ÊÜÒæÁ¼¶à£¬°Ù»¨°Ù²İºÃÏñÓĞÖÎÁÆµÄ¹¦ÓÃÈÃÄãÉíĞÄ¾õÊæ
Ì¹£¬ºÃÏñËùÓĞµÄÌÛÍ´¶¼²»¼ûÁË£¬ÊÕ»ñ²»ÉÙ¡£


LONG);
	setup();
	replace_program(ROOM);
}
