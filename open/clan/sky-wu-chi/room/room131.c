inherit ROOM;
void create() {
	set( "short", "$HIC$ĞÀ$HIR$¡õ$HIY$²İÒ©·¿$NOR$" );
	set( "owner", "lts" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 11,
		"amount2"  : 1,
		"amount3"  : 109,
		"amount7"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/dragon/obj/sunblade",
		"amount9"  : 10,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/ping/obj/neck0",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file5"    : "/open/gblade/obj/dragon_book",
		"file6"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "light_up", 1 );
	set( "build", 11246 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room127.c",
	]) );
	set( "long", @LONG
   ÕâÀïÊÇ[0;1;36m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1mU[1m¡õ[1m¡õ[1m¡õ[1mY[0mµÄ²İÒ©·¿ËùÓĞµÄ²İÒ©¶¼ÕûÆë»®Ò»µÄÅÅÁĞÔÚ²İÒ©·¿Àï
Ã¿¸ö²İÒ©¶¼É¢·¢×ÅËûÃÇµÄÏãÎ¶,µ¼ÖÂÕû¸÷·¿¼äÃÖÂş×ÅÏãÎ¶,Äã¿´µ½ÀïÃæËù
ÊÕ²ØµÄÄ§Áú÷ë¡õ.²»½ûßõßõ³ÆÆä.ËùÓĞµÄ²İÒ©ÔÚĞÀÌá.µ¶×÷Õ½Ê±,Ôò
¸øÁËĞÀÒ»µÀÇ¿¾¢µÄ»Ø¸´Á¦.....


LONG);
	setup();
	replace_program(ROOM);
}
