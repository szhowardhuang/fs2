inherit ROOM;
void create() {
	set( "short", "芭乐园" );
	set( "owner", "kiroro" );
	set( "light_up", 1 );
	set( "build", 10504 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room149",
		"west"      : "/open/clan/ou-cloud-club/room/room175",
	]) );
	set( "long", @LONG
  这里是火焰鸭和小雯种芭乐的地方,房间的正中央有一颗大大的芭乐,这只芭乐
的命相当的苦,他为了火焰鸭和小雯小敏的幸福,不惜放弃原来当杀手的志向,转
去当个可怜的小书生,再孤立无援的地方努力生存,终于解开了傲云没有人会的飘
阳之谜,现在正在努力的修炼中,以便能够更上一层楼,

LONG);
	setup();
	replace_program(ROOM);
}
