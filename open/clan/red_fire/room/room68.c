inherit ROOM;
void create() {
	set( "short", "$HIC$威洛$NOR$的$HIM$练$HIY$武$HIW$房$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/gsword/obj1/bloodsword",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/gsword/obj1/karmband",
		"file4"    : "/open/gsword/obj1/ring",
		"file5"    : "/open/main/obj/bird_legging",
		"amount4"  : 1,
		"file7"    : "/open/main/obj/m_cloak",
		"amount3"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/gsword/npc2/sadsword",
		"file3"    : "/open/gsword/obj1/khelmet",
	]) );
	set( "owner", "welo" );
	set( "build", 10139 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room115",
		"home"      : "/open/clan/red_fire/room/hall",
		"south"     : "/open/clan/red_fire/room/room59.c",
		"north"     : "/open/clan/red_fire/room/room99.c",
		"east"      : "/open/clan/red_fire/room/room72.c",
	]) );
	set( "long", @LONG

这是$HIC$威洛$HIR$练$HIG$功$HIY$习$HIC$武$NOR$的地方，房间中央练功$HIW$人偶$NOR$上斑驳的
痕迹，显示它已经使用了一段很长的时间了。地上散布
着出现$HIM$裂痕$NOR$的$WHT$铁剑$NOR$，看情况$HIC$威洛$NOR$真的投入很多心力在这
间$HIM$练$HIY$武$HIW$房$NOR$锻炼武艺。靠近东面的墙边有着一块四方形的
$HIY$坐垫$NOR$，平时$HIC$威洛$NOR$便是坐在这边锻炼内功心法。


LONG);
	setup();
	replace_program(ROOM);
}
