inherit ROOM;
void create() {
	set( "short", "$GRN$ÅÚÕóµØ$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "del" );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room147.c",
		"north"     : "/open/clan/ou-cloud-club/room/room254",
		"south"     : "/open/clan/ou-cloud-club/room/room33.c",
		"west"      : "/open/clan/ou-cloud-club/room/room118.c",
	]) );
	set( "long", @LONG
ÕâÀïÊÇÒ»Æ¬¿Õ¿õµÄ²İÔ­£¬ÂÌÓÍÓÍµÄÒ»Æ¬ÈÃÈË¿´ÁËĞÄ¿õÉñ
âù£¬ÕıÇ°·½ÓĞÒ»¿é½¹ºÚµÄµØÆ¤£¬Ô­À´ÄÇ±ß¼ÜÁËÒ»ÃÅ»ğÅÚ£¬ÉÏ
ÃæĞ´×Å[1;33m¡®¹úÔìÁùÈıÊ½Ò»¶ş¡ğ¹«ÀåÆÈ»÷ÅÚ¡¯[0m£¬ÅÔ±ß»¹Õ¾ÁË¼¸¸ö
Éí´©ÃÔ²Ê¾ü·şÕıÔÚ²ÙÁ·µÄ°¢±ø¸ç¡£²»Ô¶´¦ÓĞ¼¸Ìõ²»ÖªµÀÍ¨Íù
ºÎ´¦µÄÉîåäĞ¡¾¶£¬ºÃÆæµÄÄãÓĞµãÔ¾Ô¾ÓûÊÔÏëÈ¥Ì½ÏÕµÄ¸Ğ¾õ¡£
  
  [1;37mÒ»¶ş¡ğ¹«ÀåÆÈ»÷ÅÚ[0m(Ternch mortar)
  [1;34mÆÈ»÷ÅÚÅÚ°à°à³¤[0m(Mortar corporal)  
  [1;36mÆÈ»÷ÅÚÅÚ°àÅÚÊÖ[0m(Mortar man1 - 3)
  
LONG);
	setup();
	replace_program(ROOM);
}
