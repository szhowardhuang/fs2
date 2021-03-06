inherit ROOM;
void create() {
	set( "short", "$HIW$盾工程学研究所$NOR$" );
	set( "owner", "alucard" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/daemon/class/blademan/obj/gstone",
		"amount8"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount10" : 1,
		"amount6"  : 1,
		"file3"    : "/daemon/class/blademan/obj/gstone",
		"file10"   : "/open/common/obj/liz_meat",
		"file7"    : "/open/capital/obj/blade2",
		"amount3"  : 1,
		"file6"    : "/daemon/class/blademan/obj/fstone",
		"file5"    : "/open/capital/guard/gring",
		"file8"    : "/open/capital/obj/blade2",
		"amount2"  : 1,
		"file4"    : "/daemon/class/blademan/obj/fstone",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file9"    : "/daemon/class/blademan/obj/skykey",
		"amount1"  : 1,
	]) );
	set( "build", 10058 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room87.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room168",
	]) );
	set( "long", @LONG

    这里是傲云山庄内的冶金重地,专司研究各种强化金属的工程技术,以
期望能造出具有顶级防御能力的盾牌,尤其最近新引入了西方近代科学技术
,将电磁气引入盾牌之内,使其产生抵抗抗物理攻击之外的额外抗性,盾工程
技术的进步于是得以一日千里,传闻某位傲云山庄的高层人物正计划将自己
武学中的绝技灌注于防具之内,期望能达到化解一切劫难的功效,也因此,本
研所的人员也日夜不停的研究各种匹配,融合的方式,以早日作出更优良的
防具...

LONG);
	setup();
	replace_program(ROOM);
}
