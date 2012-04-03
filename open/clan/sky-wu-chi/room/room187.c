inherit ROOM;
void create() {
	set( "short", "$HIC$ĞÀ$HIR$¡õ$HIY$·À¾ßËù$HIB$II$NOR$" );
	set( "owner", "lts" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room109",
		"west"      : "/open/clan/sky-wu-chi/room/room169.c",
	]) );
	set( "light_up", 1 );
	set( "object", ([
		"file9"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/dancer/obj/linrboots",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/capital/guard/gring",
		"amount9"  : 1,
		"file2"    : "/daemon/class/blademan/obj/ublade",
		"file7"    : "/open/killer/obj/k_ring",
		"file3"    : "/open/killer/obj/k_ring",
		"file4"    : "/open/dancer/obj/yuawaist",
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "build", 10515 );
	set( "long", @LONG
   ÕâÀïÊÇ[0;1;36m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1mU[1m¡õ[1m¡õ[1m¡õ[1mY[0mµÄ·À¾ßËù,ËùÓĞ·À¾ß¶¼ÕûÆë»®Ò»µÄÅÅÁĞÔÚ·À¾ßËùÀï
Ã¿¸ö·À¾ß¶¼ÉÁÁÁ×ÅËûÃÇµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m~[0m,µ¼ÖÂÕû¸÷·¿¼ä[0;1m¡õ[1m{[1m¡õ[1m{[1m¡õ[1mo[1m¡õ[1mG[0m,Äã¿´µ½ÀïÃæËù
ÊÕ²ØµÄÑı»Ã·À¾ß..²»½ûßõßõ³ÆÆä......ËùÓĞµÄ·À¾ßÔÚĞÀÌáµ¶×÷Õ½Ê±,Ôò
¸øÁËĞÀÒ»µÀÇ¿¾¢µÄ·À»¤.....
vv
LONG);
	setup();
	replace_program(ROOM);
}
