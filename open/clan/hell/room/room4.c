inherit ROOM;
void create() {
	set( "short", "$HIC$kalin$HIW$µÄ$HIG$¼¦Ë¿Í·$NOR$" );
	set( "owner", "taxi" );
	set( "item_desc", ([
		"[0;5;36m¡õ[5mR[5m¡õ[5m¡õ[5m¡õ[5m¡õ[5m¡õ[5m¡õ[0m" : @ITEM

[33mcow...ÂíµÄB...É«ÀÇ[0m[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
[33mcow...ÂíµÄB...É«ÀÇ[0m
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10270 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room44.c",
		"north"     : "/open/clan/hell/room/room43.c",
		"east"      : "/open/clan/hell/room/room54.c",
	]) );
	set( "long", @LONG
    ¾­¹ıÁËÉÏ´ÎµÄ×£ÈÚÖ®ÔÖ...kalinËğÊ§²ÒÖØ...
ÔÚÍ´¶¨Ê§Í´ºó...ÖíÉñ¾ö¶¨²»ÔÙ´ò»ìÁË...
Õâ´ÎÖíÉñÑ§¹ÔÁË..ºÃºÃĞ´ĞğÊö....×÷¸÷¹Ô±¦±¦
eq..eq....»ØÀ´°É..
eq..eq ........ÎÒ°®Äã...
ÓÀÓÀÔ¶Ô¶¶¼²»crash...........
àÅ...¾Í½µ...                    :)

$HIR$´í×Ö1..Í´¶¨(Ë¼)Í´
´í×Ö2..×÷(¸ö)¹Ô±¦±¦
Åú..³¬°×³Õ....12/20..(min)µ½´ËÒ»¡õNOR$

  ÃºÓÍÚ¤Ö½µÄÊ¬Ìå(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
