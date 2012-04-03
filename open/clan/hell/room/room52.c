inherit ROOM;
void create() {
	set( "short", "$HIW$ºÚÂÖÎÔ·¿ - $HIC$ÎäÆ÷ÊÒ$NOR$" );
	set( "object", ([
		"file9"    : "/open/wind-rain/obj/bird-blade",
		"amount10" : 1,
		"file2"    : "/daemon/class/blademan/obj/gold-blade",
		"file6"    : "/open/ping/obj/iceger",
		"amount4"  : 1,
		"file1"    : "/open/ping/obj/iceger",
		"amount3"  : 1,
		"file10"   : "/open/ping/obj/cloud_fan",
		"amount6"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file4"    : "/daemon/class/fighter/figring",
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/dragon-sword",
		"amount2"  : 1,
	]) );
	set( "item_desc", ([
		"dragon_sword" : @ITEM
´Ë½£ÄËÊÇ²ØÓÚ»Æ½ğ³ÇÄÚ£¬´«ËµÖĞÄÃÁË±ãÄÜ
Ê¹¹¦Á¦ÔöÇ¿Êı±¶µÄÉñ½££¬µ«ÈôÊÇÄÚÁ¦²»¹»£¬Ôò
ÎŞ·¨¼İÔ¦´Ë½££¬·´¶ø»á±»¿ñÆøËùÍÌÊÉ£¬¿´À´Ò²
Ö»ÓĞ[0;1;31m¡õ[1mC[1m¡õ[1m][1;37m¡õ[1m¡õ[1m¡õ[1m¡õ[0m²Å¹»¸ñÄÃ´Ë½£°¢

ITEM,
	]) );
	set( "build", 10760 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room48",
		"north"     : "/open/clan/hell/room/room48",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
ÕâÀïÊÇ½£Ä§ºÚÂÖ·ÅÖÃÎäÆ÷µÄµØ·½£¬·¿¼äÀï
ÂúÊÇ²»³£¼ûµ½µÄÎäÆ÷£®ÆäÖĞ¸üÓĞÎäÁÖÆß´óÆæ±ø
Æ÷ÖĞµÄ[0;1;31m¡õ[1m¡õ[1m¡õ[1ms[1;37m¡õ[1mM[0m¡¢[0;1;36m¡õ[1m¡õ[1m¡õ[1m][1;35m¡õ[1m¡õ[1m¡õ[1mF[1;37m¡õ[1mC[0mµÈ£¬¶øÔÚÕâ·¿¼äÖĞ
Ñë·ÅÖÃµÄÕıÊÇ´«ËµÖĞ»Æ½ğ³ÇÄÚËù²ØµÄ

                [0;1m¡õ[1mp[1m¡õ[1m¡õ[1;32m¡õ[1mC[1m¡õ[1ms[1;37m¡õ[1mC[0m(Dragon_sword)


LONG);
	setup();
	replace_program(ROOM);
}
