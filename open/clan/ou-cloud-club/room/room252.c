inherit ROOM;
void create() {
	set( "short", "$HIY$Áú×¦ÃÜÊÒ$NOR$" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-claw",
		"file1"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/prayer/obj/boris-cloth",
		"file8"    : "/daemon/class/fighter/ywgem",
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 12597 );
	set( "owner", "daimon" );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room119",
	]) );
	set( "long", @LONG
          $BRED$$HIY$¡¶  $HIC$Áú   ×¦   °Â  Òå¡¡$HIY$£­¡¡$HIG$¿ñ¡¡Áú¡¡Îè¡¡ÔÆ¡¡¼Ê¡¡$HIY$¡·$NOR$

$HIC$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIC$¡¡ÄÃ¡¡ÔÆ¡¡ÇÀ¡¡Öé¡¡Ê½¡¡$HIR$¡¿$HIC$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß

$HIY$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIY$¡¡ÄÃ¡¡ÔÆ¡¡ÀÌ¡¡ÔÂ¡¡Ê½¡¡$HIR$¡¿$HIY$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß

$HIG$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIG$¡¡²¶¡¡·ç¡¡×½¡¡Ó°¡¡Ê½¡¡$HIR$¡¿$HIG$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß

$HIM$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIM$¡¡¸§¡¡ÇÙ¡¡ÀÌ¡¡ÔÂ¡¡Ê½¡¡$HIR$¡¿$HIM$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß

$HIW$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIR$¡¡Ë«¡¡Áú¡¡ÇÀ¡¡Öé¡¡Ê½¡¡$HIR$¡¿$HIW$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß

$HIB$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$HIR$¡¾$HIB$  Ë«¡¡ÖØ¡¡Ðé¡¡µ·¡¡Ê½¡¡$HIR$¡¿$HIB$¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß¡ß$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
