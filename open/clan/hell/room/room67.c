inherit ROOM;
void create() {
	set( "short", "$HIY$魔龙鳞$HIW$之界$NOR$PART3" );
	set( "build", 10957 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room56.c",
	]) );
	set( "long", @LONG

俗话说有一就有二...无三不成礼...
当然还是要努力的给它在盖下去啰...
当大家快乐的用魔龙麟飞当小飞侠时...
别忘了感谢hell辛苦的劳工弟兄...
hell的经济奇迹就是由他们开创的...

所以让我们一起来,大声的说 : 啊~ 福气啦!!

LONG);
	setup();
	replace_program(ROOM);
}
