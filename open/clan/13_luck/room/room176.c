inherit ROOM;
void create() {
	set( "short", "¹Å±¤" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10212 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room179",
	]) );
	set( "long", @LONG

    ÕâÀïÊÇ´«ËµÖĞµÄÄ§½çÖ®Ö÷[0;1;31m¡õ[1mI[1m¡õ[1m¡õ[1m¡õ[1m][1m¡õ[1m¡õ[0mµÄËùÔÚµØ¹Å±¤£¬ÀïÃæÓĞĞí
¶àµÄ»ú¹Ø£¬Ò²ÓĞĞí¶àÀ÷º¦µÄ²¿ÏÂÕòÊØ×Å¸÷¹Ø¿¨£¬[0;1;36m¡õ[1mC[1m¡õ[1m][1m¡õ[1mN[0mºÍ[0;1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m
[0;1;37m¡õ[1m¡õ[0m¸üÊÇÆäÖĞµÄÙ®Ù®Õß£¬Ò²ĞíÄÜ½ÄĞÒ´ò°ÜÕâĞ©ÈË£¬µ«ÊÇ[0;1;31m¡õ[1mI[1m¡õ[1m¡õ[1m¡õ[1m][1m¡õ[1m¡õ[0mÈ´
±ÈËûÃÇ²»Öª±äÌ¬¼¸±¶£¬ÒÔ[0;1;35m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mT[1m¡õ[1mx[0m´ò±éÌìÏÂÎŞµĞÊÖ£¬ÒªÌôÕ½ËûÒª
ÓĞ¼ûĞ¡ºÚĞ¡°×µÄĞÄÀí×¼±¸£¬Èç¹ûÄãÒÑ¾­×¼±¸ºÃÁË£¬ÄÇ¾ÍÍÆ¿ª´óÃÅ
½øÈ¥°É¡£


LONG);
	setup();
	replace_program(ROOM);
}
