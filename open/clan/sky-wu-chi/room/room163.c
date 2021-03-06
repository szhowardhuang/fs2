inherit ROOM;
void create() {
	set( "short", "翠峰" );
	set( "object", ([
		"file5"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file9"    : "/open/quests/snake/npc/obj/un_cloth",
		"file4"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"file10"   : "/open/killer/obj/k_ring",
		"file8"    : "/open/quests/snake/npc/obj/un_whip",
		"file2"    : "/daemon/class/fighter/armband",
	]) );
	set( "light_up", 1 );
	set( "build", 10960 );
	set( "owner", "herononame" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room166",
	]) );
	set( "long", @LONG
眼前一块石敢当使你停下了脚步，只见上面刻着大大的两
个字‘翠峰’，喔，原来是到了目的地了，只是，好像没看到
神仙耶，你不禁委屈的流下泪下，不过，这里还真是美丽，山
壁上一道涓丝般的瀑布缓缓的流着，四周更是充满了不少罕见
的花草走兽，虽然没看到神仙，能见到如斯美景，也算不虚此
行了。
LONG);
	setup();
	replace_program(ROOM);
}
