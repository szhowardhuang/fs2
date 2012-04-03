inherit ROOM;
void create() {
	set( "short", "Ôç°²ÉÙÅ®×é" );
	set( "owner", "xraistlin" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"file2"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
	]) );
	set( "build", 10704 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
Ôç°²ÉÙÅ®
[1;32m¼ªÔóÍ«[0m
1985/4/12/OĞÍ/çùÓñÏØ³öÉú
[1;35m¼Ó»¤ÑÇÒÀ[0m
1988/2/7/ABĞÍ/ÄÎÁ¼ÏØ³öÉú
[1;36m¹ıÏ£ÃÀ[0m
1987/6/17/OĞÍ/¶«¾©¶¼³öÉú
[1;31mÊ¸¿ÚÕæÀï[0m
1983/1/20/AĞÍ/ÉñÄÎ´¨ÏØ³öÉú
ÕâËÄ¸öÊÇÎÒ¾õµÃ×î¿É°®µÄ
LONG);
	setup();
	replace_program(ROOM);
}
