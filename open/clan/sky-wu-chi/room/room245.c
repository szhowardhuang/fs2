inherit ROOM;
void create() {
	set( "short", "[1;37m¡®[1;36m¶´ÄÚ¶´[1;37m¡¯[0m" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/open/tendo/obj/chaosbelt",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/wu/npc/obj/armband",
		"file10"   : "/daemon/class/fighter/figring",
		"amount6"  : 1,
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room206",
	]) );
	set( "owner", "roboo" );
	set( "build", 10026 );
	set( "long", @LONG

    [30;47mµ±»ğÇòÉÏÉıÔÚÕÀÀ¶Ö®ÖĞ                [0m------------------------------------
    ------------------------------------[30;47m              Ê®¸ö°«ÈËµÄÎèµ¸ÖÕ¸æÂäÄ»[0m
    [30;47m±»È¡¶ø´úÖ®µÄµÆ»ğ                    [0m------------------------------------
    ------------------------------------[30;47m                    ³Á¼ÅºÚ°µÖĞµÄÓ©¹â[0m
    [30;47m¿àÉ¬µÄ¾ÈÖú»®Èë¸¹ÖĞ                  [0m------------------------------------
    ------------------------------------[30;47m                  ±ùÀäµÄ´ÌÍ´Ï´È¥¿àÉ¬[0m
    [30;47m×ÆÌÌµÄºìÉ«ÔÚÑÛÇ°»ÓÎè                [0m------------------------------------
    ------------------------------------[30;47m                  »ÒÉ«µÄÄ£ºı½¥½¥Òş²Ø[0m
    [30;47mĞé¼ÙµÄÉúÃüÖ®ìé½«±»¹Ø±Õ              [0m------------------------------------
    ------------------------------------[30;47m                ²»ËÀÕß½«½øÈëÄ¹µØ°²Ï¢[0m

LONG);
	setup();
	replace_program(ROOM);
}
