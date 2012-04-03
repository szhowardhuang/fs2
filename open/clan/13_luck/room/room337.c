inherit ROOM;
void create() {
	set( "short", "±ÈÎäµÀ" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/killer/headkill/obj/w_dag",
		"file3"    : "/open/killer/headkill/obj/e_dag",
		"amount3"  : 1,
		"file2"    : "/open/killer/headkill/obj/e_dag",
		"file1"    : "/open/killer/headkill/obj/f_dag",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"amount6"  : 1,
		"file6"    : "/open/killer/headkill/obj/f_dag",
	]) );
	set( "build", 10206 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room336",
		"north"     : "/open/clan/13_luck/room/room338",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    ÄãÓÖ×ªÁË¼¸¸öÍä£¬ÈıÖê[0;1;32m¡õ[1mj[1m¡õ[1mQ[1m¡õ[1m¡õ[0m³åÌì¶øÆğ£¬µØÏÂÓÖÓĞ[0;1;33m¡õ[1m¡õ[1m¡õ[1mD[0m£¬[0;1;30m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÈ
¿ó²Ø£¬µØÆøÌØÅ¯£¬[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m}[0m¡£ÄãĞĞ³öÊı²½£¬ÒşÒşÌıµÃÊ÷ÁÖÖĞ´«À´±øÈĞ
Ïà½»Ö®ÉùÄãÓĞĞ©½¹¼±ÊÇÇ°È¥¿´£¬Ô­À´ÊÇ[0;1;34m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mºÍ[0;1;36m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄÃÅÍ½ÔÚ»¥Ïà
[0;1;35m¡õ[1m¡õ[1m¡õ[1mR[1m¡õ[1mZ[1m¡õ[1m¡õ[0m£¬Äã¿´µ½ÖÚ¶à¸ßÊÖÔÚÇĞ´è£¬ÒıÆğÁËÄãºÃÕ½µÄĞÄÀï£¬ÄãÒ²ÈÌ²»
×¡ÏëÈ¥Ò»Æğ±ÈÊÔÒ»ÏÂ¡£


LONG);
	setup();
	replace_program(ROOM);
}
