inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$□$HIY$防具所$NOR$" );
	set( "owner", "lts" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/mogi/castle/obj/leave",
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/quests/snake/npc/obj/snake_gem",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room108",
		"east"      : "/open/clan/sky-wu-chi/room/room187.c",
		"west"      : "/open/clan/sky-wu-chi/room/room72.c",
	]) );
	set( "long", @LONG
    这里是夜空下的欣的防具所,所有防具都整齐划一的排列在防具所里
每个防具都闪亮着他们的光芒,导致整各房间闪闪发亮,你看到里面所
收藏的妖幻防具..不禁啧啧称其......所有的防具在欣提刀作战时,则
给了欣一道强劲的防护.....

LONG);
	setup();
	replace_program(ROOM);
}
