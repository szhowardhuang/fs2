// Room : /open/clan/sky-wu-chi/room/room113.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "sign" : "´ËÎİÊÇ¡¾Ê¥»ğ½Ì¡¿Ì«×Ó(James) ËùÓĞ¡£
",
]) );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"enter"     : "/open/clan/sky-wu-chi/room/room114.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
]) );
	set( "short", "Ğ¡·ÉÏÀ£®ÉñÃØĞ¡µÀ" );
	set( "object", ([
		"amount4"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10003 );
	set( "owner", "heronotme" );
	set( "light_up", 1 );
	set( "long", @LONG
Äã²»Öª²»¾õµÄ×ß½øÁËÒ»¸öÉñÃØµÄĞ¡µÀ£¬µ±Äã¿´µ½Ô¶·½³öÏÖÒ»µ½Áé
¹â..¾Í²»ÓÌ×ÔÖ÷µÄÇ£ÒıÍùÇ°Âõ½ø£¡Ö±µ½Äã»ØÉñºó..ÑÛÇ°³öÏÖÒ»×ù·º×Å
Áé¹âµÄĞ¡Îİ£¬´ËÊ±ÈÃÄãĞÄÖĞÓĞ×Å²»ÏêµÄÔ¤¸Ğ..ÔÚÄãÃ°Àäº¹µÄÍ¬Ê±£¬¿´
µ½Ô¶·½Ğ¡ÎİÅÔÓĞ¸öÒ»[33mÄ¾ÅÆ(sign)[0m£¬ÉÏÃæËÆºõĞ´ÁËĞ©Ê²Ã´×Ö£¡ÓÚÊÇÄãÆğ
ÁË²½ÍùÇ°¾¿Öª£¬µ±Äã¿¿½üÊ±Äã¸Ğ¾õÓĞÒ»¹ÉÁéÆøÖ±±ÆÓÚÄã¡£

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡$HIW$(´ËµØÄı¾ÛÒ»¹ÉºÜÇ¿´óµÄÁéÆø)$NOR$
LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "ÌìµÀÎŞ¼«" );
	setup();

	}
