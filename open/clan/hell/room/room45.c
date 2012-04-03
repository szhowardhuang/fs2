inherit ROOM;
void create() {
	set( "short", "$HIR$ÃÜÊÒ$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount2"  : 1,
		"file2"    : "/open/main/obj/et_sword",
	]) );
	set( "item_desc", ([
		"ºÚÂÖµñÏñ" : @ITEM
ÕâÊÇ´«ËµÖĞ¨ÉºÚÂÖ
ÕâÊÇ´«ËµÖĞ¨ÉºÚÂÖ
[31mÕâÊÇ´«ËµÖĞ¨ÉºÚÂÖ[0m
ITEM,
	]) );
	set( "build", 11515 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room56",
	]) );
	set( "long", @LONG
×ßµ½ÕâÀï£¬ÄãÃôÈñµÄÉíÌå¸Ğ¾õµ½ÁË¿ÕÆøµÄÄıÖØÃ¿
ÏòÇ°Ò»²½£¬¾Í·Â·ğ½«±»ËºÁÑÒ»°ã£¬Ô½ÊÇÔË¹¦¿¹ºâ£¬Ô½
ÊÇÍ´¿à£¬Õâ²»ÊÇÒ»°ãÈËÄÜ´ıµÄµØ·½°¢£®

             [0;1;35m¡õ[1mr[1;31m¡õ[1mC[1m¡õ[1m][1;35m¡õ[1mr[0m [0;1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m

               [0;1m¡õ[1mi[1;36m¡õ[1mm[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1;37m¡õ[1mj[0m


LONG);
	setup();
	replace_program(ROOM);
}
