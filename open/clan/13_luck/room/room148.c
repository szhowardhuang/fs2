inherit ROOM;
void create() {
	set( "short", "沙漠" );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file1"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/lingzhi",
		"amount2"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "dancer" );
	set( "build", 12166 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room54",
	]) );
	set( "long", @LONG
你在不知不觉中走到了这片荒无的[0;1;32m□[1mF[1m□[1mz[0m，已不知身
处在何方，放眼望去一片[0;1;32m□[1mF[1m□[1ma[0m，让身处在这的你不知该
往何处走去，这时在你的身旁吹起了一阵[0;1;33m□[1mg[1m□[1m□[0m，好像在
警示你踏入了不该踏入的[0;1;36m□[1m□[1m□[1m□[0m，你鼓起了勇气逆着狂风
，寻找着这阵狂风的源头，这时你发现在狂风中有一处
[0;1;31m□[1m□[1m□[1mH[0m，于是你向着这个[36m未知地[0m前进。
LONG);
	setup();
	replace_program(ROOM);
}
