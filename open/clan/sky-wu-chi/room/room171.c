inherit ROOM;
void create() {
	set( "short", "ÈçÃÎËÆ»Ã" );
	set( "object", ([
		"amount2"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"file2"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/capital/obj/blade2",
		"file1"    : "/obj/gift/lingzhi",
		"file7"    : "/open/poison/obj/blue_key",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
	]) );
	set( "owner", "roboo" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room206",
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "long", @LONG
Äã»ĞÈô½øÈëÒ»¸ö[36mÆ®ÃìĞéÎŞ[0mµÄ¿Õ¼ä,Ö»¾õµÃ¿ìÒª[31mÎŞ·¨ºôÎü[0m,Äã¸Ğ¾õÓĞË«
ÑÛ¾¦ÕıÔÚ¶¢×ÅÄã¿´,µ«ÊÇÄã»·¹ËËÄÖÜ,²¢Ã»ÓĞÈÎºÎ¶«Î÷´æÔÚ,ºöÈ»ÄãÉíĞÎ
Âä¿Õ,ÍùÏÂ[35m‰—Âä[0m,Õıµ±Äã¿ìÒªµøÂäµØÃæÖ®Ê±,ÄãºöÈ»[33m¾ªĞÑ[0m!·¢ÏÖ¸Õ²ÅµÄÒ»ÇĞ
Ö»ÊÇ[37m»Ã¾õ[0m,ÈÃÄã¾õµÃËÉÁËÒ»¿ÚÆø.

LONG);
	setup();
	replace_program(ROOM);
}
