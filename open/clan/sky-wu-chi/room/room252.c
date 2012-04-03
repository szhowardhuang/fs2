inherit ROOM;
void create() {
	set( "short", "[1;31mÄÚÉ½ÀíÃû[0mÖ®¼ä" );
	set( "object", ([
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"amount2"  : 1,
		"file1"    : "/open/snow/obj/book",
		"file3"    : "/open/dancer/obj/yuawaist",
		"file2"    : "/daemon/class/fighter/star",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10452 );
	set( "owner", "xraistlin" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
ÄÚÉ½ÀíÃû
ÉúÈÕ 1981Äê11ÔÂ7ÈÕ
³öÉúµØ ÉñÄÎ´¨ÏØ 
ÑªĞÍ OĞÍ 
ĞÇ×ù ÌìĞ«×ù 
Éí¸ß 157cm 
ÈıÎ§ B-79cm W-56cm H-79cm 
ĞËÈ¤ ÆïÂí¡¢×öÎ÷µã-ÓÈÆäÊÇÏã½¶µ°¸â 
ÌØÊâ¼¼ÄÜ ÊéµÀ7¶Î¡¢ÓÎÓ¾¡¢µ¥»É¹Ü 
×ÔÈÏÃÔÈËÖ®´¦  ÑÛ¾¦ (àÅ~ÕæµÄºÜÃÔÈË) 
LONG);
	setup();
	replace_program(ROOM);
}
