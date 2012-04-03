inherit ROOM;
void create() {
	set( "short", "¿ñ²ÐÄ§-ÀË×Ó¾Ó" );
	set( "object", ([
		"amount5"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/obj/gift/xisuidan",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"amount8"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount6"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10302 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room184",
		"south"     : "/open/clan/13_luck/room/room88.c",
		"east"      : "/open/clan/13_luck/room/room185.c",
	]) );
	set( "long", @LONG
ÄãÌ¤½ø´ËµØ£¬¿´¼ûÁù¸ö×Ö¡±[0;1;34m¡õ[1mg[1;36m¡õ[1m¡õ[1;31m¡õ[1m][0m-[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[0m¡±Ö»¾õµÃÐÄÖÐ·ºÆðÒ»¹ÉÄª
ÃûµÄ¿Ö¾å£¬´ËÊ±Ïëµ½¡±[0;1;35m¡õ[1m¡õ[1m¡õ[1ml[1m¡õ[1m~[0m ¡±£¬²ÅÖªµÀÔ­À´½øÁË[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0mµÄµØÅÌ£¬ÕâÊÇ[0;1;34m¡õ[1m¡õ[0m
[0;1;34m¡õ[1m][1m¡õ[1m¡õ[1m¡õ[1ml[0mµÄ·¿¼ä£¬µ«ËÄÖÜÎ§²¢ÎÞÊ²Ã´¶«Î÷£¬Ö»ÊÇÒ»ÑÛÍûÈ¥£¬½Ô¿´²»µ½¾¡Í·£¬
µÈÄã×ßµ½×î½üµÄÒ»ÃæÇ½Ê±£¬·¢ÏÖÇ½ÉÏ¶¼ÊÇ[0;1;7;30m¡õ[1;7mM[1;7m¡õ[1;7m¡õ[0m£¬ÓÉ´Ë¿ÉÖª[0;1;5;34m¡õ[1;5m¡õ[1;5m¡õ[1;5ml[0mµÄ[0;1;36m¡õ[1m\[1m¡õ[1mO[0m¼°Îª
[0;1;31m¡õ[1mT[1m¡õ[1m¡õ[0m¡¢[0;1;33m¡õ[1mM[1m¡õ[1m¡õ[0m¸ú[0;1;32m¡õ[1m¡õ[1m¡õ[1mM[0mËù×öÏÂµÄÅ¬Á¦¡£


LONG);
	setup();
	replace_program(ROOM);
}
