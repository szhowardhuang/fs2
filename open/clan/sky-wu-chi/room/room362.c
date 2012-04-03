inherit ROOM;
void create() {
	set( "short", "寒霜居-归真之间" );
	set( "light_up", 1 );
	set( "owner", "roboo" );
	set( "build", 10431 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room358",
	]) );
	set( "long", @LONG
　　原本以为在这个藏经阁中会有失传的武学典籍，但实际看看也不
过就只有一些比较常看见的书籍，当你慢慢的向里面走去的时候，你
突然发觉在这房间的顶端好像有一座小阁楼，你马上施展轻功向那座
阁楼跃去。原来这座阁楼才是收藏真正武学典籍的地方，在这里有天
子手中才有的神秘书籍，以及被收藏在魔龙塔中的狂龙刀谱，甚至还
有记载可以使人暴升两倍防御力的极火金身的极火真经。
LONG);
	setup();
	replace_program(ROOM);
}
