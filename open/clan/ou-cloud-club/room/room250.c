inherit ROOM;
void create() {
	set( "short", "(深情不语)" );
	set( "owner", "zuba" );
	set( "light_up", 1 );
	set( "build", 10188 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room249",
	]) );
	set( "long", @LONG
这是语情深用来思考的地方........think
小语似乎不常回来这个地方.........
有时常常听到小语一个人独自发呆想者事情
小语似乎常常叹气也不知发生了何事
也许有些事是小语要独自面对的吧.....
旁边有个床......是小语休息的地方...ZzZzZz




LONG);
	setup();
	replace_program(ROOM);
}
