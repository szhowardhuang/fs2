inherit ROOM;
void create() {
	set( "short", "ÃÔÎíÖ®µÀ" );
	set( "object", ([
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount3"  : 1,
	]) );
	set( "owner", "smalloo" );
	set( "build", 10653 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room335",
		"north"     : "/open/clan/13_luck/room/room337",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    Òõ·çÕóÕó£¬ËÍÀ´ÁËÒ»ÍÅÍÅµÄ[0;1m¡õ[1mg[1m¡õ[1m¡õ[0m£¬Ê¹µÃÂ·¾¶±äµÃÓúÀ´Óú[33mÃÔºı[0m¡£Ê¹
ÄãÍ»È»¾ªÏÅÁËÒ»Ìø£¬ÄãÖåÒ»Öå[0;1;30m¡õ[1m¡õ[1m¡õ[1mY[0m£¬¼±Ã¦µÄ¿´Çå³şÁËµÀÂ·£¬¼±¼±Ã¦Ã¦
µÄÍùÕıÈ·µÄÂ·Í¾³åÈ¥¡£Éñ·çÖ®ÕæÊÇÈÃÈË¸Ğ¾õ¡õ[0;1;5;34mo[1;5m¡õ[1;5mS[1;5m¡õ[1;5m_[1;5m¡õ[1;5mS[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0mµÄµØ·½£¬Äã
Ò»Ê±Ò²²»Ã÷°×ÆäÖĞµÄÃØ°ÂËùÔÚ£¬´ËÊ±ºñºñºÚºÚµÄÔÆ²ã´µ¹ıÀ´£¬Ñ¹µÃÄã
´­²»¹ıÆøÀ´£¬Á¬Ã¦[0;1;33m¡õ[1mB[1m¡õ[1m\[0m×Ô±£¡£


LONG);
	setup();
	replace_program(ROOM);
}
