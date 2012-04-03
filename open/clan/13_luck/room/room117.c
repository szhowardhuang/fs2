inherit ROOM;
void create() {
	set( "short", "ÀË×Ó¾ÓÓÒµî" );
	set( "owner", "roar" );
	set( "object", ([
		"file8"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/bingtang",
		"amount10" : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10341 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room88",
	]) );
	set( "long", @LONG
ÕâÀïÊÇ[0;1;31m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[1m¡õ[1m¡õ[1m¡õ[1mk[1m¡õ[1m¡õ[0m£¬Ç½ÉÏµÄ[0;1;30m¡õ[1m¡õ[1m¡õ[1m¡õ[0m¿Ì»®×Åµ±Äê[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5m][1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0m½â[0;1;31m¡õ[1mT[1m¡õ[1m¡õ[0m£¬[0;1;33m¡õ[1mM[1m¡õ[1m¡õ[0mºÍ[0;1;32m¡õ[1m¡õ[1m¡õ[1mM[0m
µÄÕ½¿ö¡£µ±³õ[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0mÖ®ËùÒÔÃ»[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[0mÕû¸ö[0;1;31m¡õ[1mZ[1m¡õ[1mL[0mµÄ×î´óÔ­Òò±ãÊÇÔÚÕâÈý¸öÃ»ÍêÈ«½âµ½£¬
Ô­±¾Àë[0;1;5;32m¡õ[1;5mZ[1;5m¡õ[1;5mL[1;5m¡õ[1;5mM[1;5m¡õ[1;5m¡õ[0mÖ®Î»½ö²îÒ»²½£¬¾ÍÒò¿ñÏëÖØ¿ª¶øÖÐ¶Ï¡£¹ÊÆäÅ­ÑÔµÀ£º
                
                ¡®[0;1;5;31m¡õ[1;5m`[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m@[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mA[1;5m¡õ[1;5mn[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mU[1;5m¡õ[1;5mZ[1;5m¡õ[1;5mL[1;5m¡õ[1;5mA[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mV[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5mC[0m¡¯

LONG);
	setup();
	replace_program(ROOM);
}
