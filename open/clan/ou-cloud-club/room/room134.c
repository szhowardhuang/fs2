inherit ROOM;
void create() {
	set( "short", "$HIR$Ω£$HIC$…Ò$NOR$÷Æ$HIY$”Ú$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount2"  : 4,
		"amount3"  : 1,
		"file5"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount5"  : 1,
		"file1"    : "/open/mogi/castle/obj/leave",
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/gsword/obj/dragon-sword",
		"file3"    : "/open/scholar/obj/icefan",
	]) );
	set( "build", 10022 );
	set( "light_up", 1 );
	set( "owner", "left" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room18",
	]) );
	set( "long", @LONG

                                      [14m®}®|®{®z®y[0m
                                      [14m    ®Å [0m
                                      [16m  ®ç®ã®é[0m
 [19m ®ç®Ä®Ä®è®ç®Ä®Ä®Ä®è®ç®Ä®Ä®Ä®Ä®è®ç®Ä®Ä®Ä[0m/®X®[®é[16m®h®h®h®h®h®h®h®r®é[0m
 [19m ®ê®Ä®Ä®é®ê®Ä®Ä®Ä®é®ê®Ä®Ä®Ä®Ä®é®ê®Ä®Ä®Ä[0m®^®a/®è[16m®k®k®k®k®k®k®k®s®è
                                        [16m®ê°¯®è[0m        
                                        [14m  ®Å [0m
                                     [14m ®y®z®{®|®} [0m

°Æ°°[21mÀÊ°°–ƒ°°ÀÊ°°“‚°°ÀÊ°°Ω£°°“‚
°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°[0m£¨
°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°[20mΩ£°°–ƒ°°Ω£°°“‚°°Ω£°°»Î°°…Ò°°[0m°Ø
LONG);
	setup();
	replace_program(ROOM);
}
