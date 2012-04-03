inherit ROOM;
void create() {
	set( "short", "$HIW$∫⁄¬÷Œ‘∑ø - $HIC$≤ÿ±¶ “$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file10"   : "/open/mogi/dragon/obj/key",
		"amount1"  : 1,
		"file1"    : "/open/snow/obj/snow_token",
		"amount9"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/snow/obj/sky_lin_stone",
		"file9"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/obj/gift/xiandan",
		"file5"    : "/open/scholar/obj/iron",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mogi/castle/obj/blood-water",
	]) );
	set( "item_desc", ([
		"osword" : @ITEM





[0;1;36m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1;37m°ı[1mu[1m°ı[1m@[1m°ı[1m°ı[0m


ITEM,
		"oblade" : @ITEM



[0;1;36m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1;37m°ı[1mu[1m°ı[1m@[1m°ı[1m°ı[0m


ITEM,
	]) );
	set( "build", 10088 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room41.c",
		"south"     : "/open/clan/hell/room/room53",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
¥À∑øŒ™∫⁄¬÷∆Ω ±¥”Œ‰¡÷÷–£¨ªÒµ√µƒœ£ ¿’‰
±¶£¨ªÚ «œ…µ§√Ó“©£¨À˘÷√∑≈µƒµÿ∑Ω£¨ƒ„œÎ…œ«∞
“ª¿¿’‚–©œ£ “’‰±¶£¨≤ª¡œ»¥≈‹≥ˆ¡À¡Ω∏ˆ ◊Œª◊Ë
µ≤£Æ

[0;1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mu[1m°ı[1m@[1m°ı[1m°ı[0m°∏[0;1;37m°ı[1m@[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mM[1;33m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mM[0m°±“ªµ∂ÕÚ…±(oblade)
[0;1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mu[1m°ı[1m@[1m°ı[1m°ı[0m°∏[0;1;33m°ı[1m@[1m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[1;37m°ı[1m°ı[1m°ı[1m°ı[1m°ı[1mC[0m°±“ªΩ£ÕÚ…˙(osword)

LONG);
	setup();
	replace_program(ROOM);
}
