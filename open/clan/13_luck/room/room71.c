inherit ROOM;
void create() {
	set( "short", "烟雨楼五楼" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room354",
		"north"     : "/open/clan/13_luck/room/room75.c",
		"south"     : "/open/clan/13_luck/room/room74.c",
		"up"        : "/open/clan/13_luck/room/room76.c",
		"down"      : "/open/clan/13_luck/room/room54.c",
		"west"      : "/open/clan/13_luck/room/room73.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼五楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，到了晚上时，
凉凉的徐风吹来，轻轻的打在脸颊上犹如按摩皮肤一般的舒服，吹着
微风吃着小点心，也是别有一般风趣。

LONG);
	setup();
	replace_program(ROOM);
}
