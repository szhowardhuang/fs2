inherit ROOM;
void create() {
	set( "short", "ÎäÆ÷½»»»µØ" );
	set( "object", ([
		"file5"    : "/obj/gift/xisuidan",
		"file2"    : "/open/gblade/obj/dragon_book",
		"file9"    : "/obj/gift/unknowdan",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount7"  : 13,
		"amount8"  : 1,
		"file7"    : "/open/ping/obj/poison_pill",
	]) );
	set( "owner", "roar" );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room186",
	]) );
	set( "long", @LONG
±éµØµÄ±¦µ¶Ãû½££¬²»ÄÑÏëÏñÄãÒÔÀ´µ½ÁËÒ»¸öÎäÆ÷µØ·½£¬µ«ÊÇ±éµØµÄµ¶½£È´ÎŞ
ÈË¿´¹Ü£¬´ÏÃ÷µÄÄãÒ²ÖªµÀÕâ²»µ¥´æ£¬È»¶øÍùÀïÃæ×ßÈ¥£¬È´·¢ÏÖÒ»¿ÃÊ÷£¬ËüÃû½Ğ¡±
[0;1;32m¡õ[1mi[1m¡õ[1mC[1m¡õ[1m¡õ[0m¡±¾İËµ¿ÉÒÔ¡±[0;1;35m¡õ[1mH[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¡±µ«ÊÇÄãËùÒª»»µÄ¶«Î÷±ØĞëÄÃ±ÈÄÇ¶«Î÷ºÃµÄÌõ¼ş£¬
´ËÊ±Äã·¢ÏÖÓĞÒ»Ë«µ¶ÕıµôÏÂÀ´£¬ÓĞÒ»¸öÈËÔÚÄÇË«ÊÖ¸ß¾ÙµÄ½ÓÏÂ£¬

LONG);
	setup();
	replace_program(ROOM);
}
