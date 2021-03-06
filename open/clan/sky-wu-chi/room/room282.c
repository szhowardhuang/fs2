inherit ROOM;
void create() {
	set( "short", "白鹤泉" );
	set( "owner", "shih" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"amount3"  : 34,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount9"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
	]) );
	set( "build", 11436 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room244",
	]) );
	set( "long", @LONG
相传从前这里有一个白鹤泉，它的水清凉甘甜，为此山之最。
这泉水长年涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因以
为名。可惜后来有一个自私自利的小官，独霸了泉水，后来更因迷
信风水之说，把泉眼堵塞，白鹤泉从此便干涸了。现在只剩下一座
刻着「白鹤泉”三字的石坊以为纪念。从这里继续北上，便是上山
之路。

LONG);
	setup();
	replace_program(ROOM);
}
