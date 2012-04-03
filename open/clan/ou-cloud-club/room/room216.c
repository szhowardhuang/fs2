inherit ROOM;
void create() {
	set( "short", "$HIC$龙$HIG$林$HIY$武圣居$NOR$" );
	set( "object", ([
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"file8"    : "/open/wu/npc/obj/armband",
		"file7"    : "/open/ping/obj/chilin_legging",
		"file10"   : "/open/dancer/obj/yuawaist",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-claw",
		"file1"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/daemon/class/fighter/figring",
		"amount4"  : 1,
		"file9"    : "/open/ping/obj/gold_hand",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 14669 );
	set( "light_up", 1 );
	set( "owner", "kingsir" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room214",
	]) );
	set( "long", @LONG
这是$HIC$龙$HIG$林$HIY$武圣$NOR$的王殿有一股逼人的$HIC$气势$NOR$只见$HIY$武圣
$NOR$身旁那把$HIR$绝$HIC$世$HIB$兵$HIM$器$HIC$－$HIR$破$HIY$龙刃$HIC$－$NOR$忽然发现刚那股$HIC$气势$NOR$竟
然犹如$HIB$大海狂涛$NOR$般的一直由这把$HIY$上古$HIC$神兵$NOR$传出．

LONG);
	setup();
	replace_program(ROOM);
}
