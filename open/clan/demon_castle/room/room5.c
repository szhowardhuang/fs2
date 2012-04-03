// Room : /open/clan/demon_castle/room/room5.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "Ä§¨BÑª³ØÁÖ" );
	set( "light_up", 1 );
	set( "build", 7150 );
	set( "clan_room", "¶ñÄ§³Ç" );
	set( "exits", ([ /* sizeof() == 6 */
  "north" : "/open/clan/demon_castle/room/room6.c",
  "south" : "/open/clan/demon_castle/room/room7.c",
  "down" : "/open/clan/demon_castle/room/hall",
  "west" : "/open/clan/demon_castle/room/room9.c",
  "up" : "/open/clan/demon_castle/room/room10.c",
  "east" : "/open/clan/demon_castle/room/room8.c",
]) );
	set( "long", @LONG

    [1m[37mÕâÀïÊÇ[31m¶ñÄ§³Ç[37mÄÚµÄ[35mÑª³Ø[36mÁÖ[37m£¬ÒàÊÇÎäÁÖÀÏÒ»±²ÈË¿ÚÖĞµÄ[33m½­ºş½ûµØ[37m£¬[0m
[1m[37mÏà´«ÔÚÊıÊ®ÄêÇ°ÎäÁÖÖĞ³öÏÖÁËÒ»Î»Îä¹¦¼«Îª¸ßÇ¿µÄ[32mÓù½£[34m·ÉÁú[36m¸µ½£º®[37m£¬[0m
[1m[37mÍ³Áì×Å[32m¶ş×ğÕß[33m¡¢[36mËÄ°ÔÍõ[33m¡¢[31m°ËÄ§Ê¹[37mÎªÁËÀíÏë¶øÕ½±é´ó½­ÄÏ±±Î´·êµĞÊÖ£¬[0m
[1m[37mÊıÄêÇ°³ÉÁ¢[31m¶ñÄ§³Ç[37mºó[31m´ó¶ñÄ§[36m¸µ½£º®[37m±ãÂÊÁìÆäÏÂÒş¾ÓÓÚ´Ë£¬×¨ĞÄµÄĞŞÁ·[0m
[1m[37mÎäÑ§Ö®[32m×î¸ß¾³½ç[37m£¬ÆñÖª½üÄêÄÚÎäÁÖÖĞ·×ÂÒ²»Ğİ£¬ÈºÇ¿Õù°Ô£¬¶øÒş¾ÓÓÚ[0m
[1m[35mÑª³Ø[36mÁÖ[37mÄÚµÄÖÚ¸ßÊÖÊÇ·ñ»áÒò´Ë¶øÔÙ¶ÈÌ¤ÉÏ[31mÑªĞÈÖ®Â·[37m¡£[0m

LONG);
	setup();

	}
