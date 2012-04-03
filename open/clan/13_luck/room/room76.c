inherit ROOM;
void create() {
	set( "short", "烟雨楼六楼" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room340",
		"down"      : "/open/clan/13_luck/room/room71.c",
		"east"      : "/open/clan/13_luck/room/room77.c",
		"up"        : "/open/clan/13_luck/room/room83.c",
		"north"     : "/open/clan/13_luck/room/room79.c",
		"south"     : "/open/clan/13_luck/room/room80.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼六楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，往东南边看去
，妳看到那也是灯火通明，感觉的出来那边是非常热闹的地方，询问
了一下店小二，确定那而是十三吉祥最热闹的地方‘日郡’。

LONG);
	setup();
	replace_program(ROOM);
}
