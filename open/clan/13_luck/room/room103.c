inherit ROOM;
void create() {
	set( "short", "ÀË×Ó¾Ó×óµî" );
	set( "owner", "roar" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
	]) );
	set( "build", 12870 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room88",
	]) );
	set( "long", @LONG
[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m£¬µØÉÏÆÌ×Å[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[0mµÄ²¨Ë¹µØÌº£¬Á½ÅÔ¸÷ÓĞÒ»ÅÅ[0;1;33m¡õ[1m[[1m¡õ[1m¡õ[1m¡õ[1mO[1m¡õ[1mW[0m£¬µÆ
ËùÉ¢·¢³öµÄ[0;1;33m¡õ[1m¡õ[1m¡õ[1m~[0mÕÕê××ÅÕû¸ö[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[0m£¬ÖĞ¼ä°Ú×ÅÒ»ÃæºÚÉ«[31mÌ´Ä¾[0mËùÔìµÄ´óĞÍÔ²
×À¡£Ô­À´ÕâÀïÊÇ[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0mÓë[0;1;33m¡õ[1mQ[1m¡õ[1mT[1m¡õ[1mN[1m¡õ[1m¡õ[0m¸÷´óÍæ¼Ò¿ª»áµÄµØ·½£¬ÈôÓöµ½½ô¼±ÊÂ¹ÊÔò
Ô¶·½µÄ[0;1;5;36m¡õ[1;5m¡õ[1;5m¡õ[1;5mj[1;5m¡õ[1;5m¡õ[1;5m¡õ[1;5m¡õ[0m-[0;1;32m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1ms[1m¡õ[1m¡õ[0mÒà»áÀ´µ½ÕâÉÌÌÖ×÷Õ½´ó¼Æ¡£
LONG);
	setup();
	replace_program(ROOM);
}
