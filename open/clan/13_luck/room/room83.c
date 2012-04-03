inherit ROOM;
void create() {
	set( "short", "烟雨楼七楼" );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room76.c",
		"east"      : "/open/clan/13_luck/room/room84.c",
		"up"        : "/open/clan/13_luck/room/room90",
		"north"     : "/open/clan/13_luck/room/room86.c",
		"west"      : "/open/clan/13_luck/room/room89.c",
		"south"     : "/open/clan/13_luck/room/room81.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼七楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，在漫长的夜晚
，也不知要做些什么，突发奇想就跟店小二叫个叉烧炒饭，没想到这
儿不但风景美，连‘炒饭’都这么美味可口。

LONG);
	setup();
	replace_program(ROOM);
}
