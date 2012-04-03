// Room : /open/clan/sky-wu-chi/room/room49.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
    Ò»×ß½ø·¿¼ä,ÄãÒşÔ¼ÎÅµ½Ò»¹ÉÆæ¹ÖµÄ[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[0m,ÈÃÄã¸Ğµ½Òì³£ÄÑÊÜ,
¶øÔÚ±±ÃæµÄÇ½ÉÏ,¿Ì×ÅÒ»ĞĞ×Ö ¡¸[0;1;31m¡õ[1mA[1m¡õ[1m^[1m¡õ[1m¡õ[1m,[1m¡õ[1mw[1m¡õ[1mO[1m¡õ[1m¡õ[1m¡õ[1m~[1m¡õ[1m¡õ[0m¡± ÏÔÏÖ³öÖ÷ÈËÉîºñµÄ¹¦Á¦
ÄãµÄÄ¿¹â½Ó×Å×ªÏò·¿¼äµÄÓÒ°ë±ß,Äã¿´µ½ÁËĞí¶à[0;1;31m¡õ[1mK[1m¡õ[1mW[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m_[1m¡õ[1mc[0m,
ÔÚÄã×ß½ü±¦ÏäÖ®Ê±,ºöÈ»´Ó·¿¼äÒ»½ÇÉä³öÒ»Ğ©°µÆ÷,ºÕÈ»¾¹ÊÇ¡¸[0;1;31m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1m¡õ[1mw[0m¡±
Äã¾ªÏÕµÄ¶ã¹ı°µÆ÷,Ò²ÏÅ³öÒ»ÉíÀäº¹,ÄãĞÄÖĞÖ»Ïë×ÅÒª¸Ï½ôÀë¿ªÕâÀï.

LONG);
	set( "short", "ĞÒÔËÖ®¼ä" );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/killer/obj/s_pill",
		"amount10" : 1,
		"file8"    : "/open/killer/obj/dagger",
		"file5"    : "/open/killer/headkill/obj/f_dag",
		"file10"   : "/obj/gift/hobowdan",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/clan/area/home/trap",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount2"  : 57,
		"file2"    : "/open/killer/obj/black",
		"amount1"  : 1,
		"amount4"  : 95,
		"file1"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "owner", "luckyneck" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room56",
	]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "ÌìµÀÎŞ¼«" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
