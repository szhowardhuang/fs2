inherit ROOM;
void create() {
	set( "short", "邪月回廊测试连结  v" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room193.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    走进这里,便见一座香烟袅袅的大香炉坐落于广大的大厅之中
炉内飘出了一阵阵让你精神气爽的白烟,使你惊讶的是,原来这是
天道无极帮主~~~[0;1;36m□[1mM[1m□[1m□[1m□[1mP[1m□[1mJ[0m以内力所激发出来的...........

<----[0;1;33m□[1mp[1m□[1m□[1m□[1mk[1m□[1m□[1m□[1m□[1m□[1m□[0m   [0;1;33m [1m□[1mp[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m-[1m-[1m-[1m-[1m>[0m

LONG);
	setup();
	replace_program(ROOM);
}
