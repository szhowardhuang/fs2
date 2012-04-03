inherit ROOM;
void create() {
	set( "short", "凤凰楼六楼" );
	set( "build", 18 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room101.c",
		"west"      : "/open/clan/13_luck/room/room236.c",
		"east"      : "/open/clan/13_luck/room/room286.c",
		"up"        : "/open/clan/13_luck/room/room342",
		"north"     : "/open/clan/13_luck/room/room237.c",
		"south"     : "/open/clan/13_luck/room/room265.c",
	]) );
	set( "long", @LONG

　　在店小二的引领，你沿着灯火照亮的楼梯往上爬，来到了凤凰楼
六楼的通道，往你的厢房走去。夜里，徐徐的凉风吹来，真是舒畅。
倾靠在护栏上仰望着明月以及满天的星斗，暂时忘却一切烦恼，忘却
一切的斗争，静静的欣赏美丽的夜景。

LONG);
	setup();
	replace_program(ROOM);
}
