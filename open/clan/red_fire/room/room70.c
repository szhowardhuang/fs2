inherit ROOM;
void create() {
	set( "short", "$HIC$【$HIM$大饭店 $HIY$大厅$HIC$】$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/red_fire/room/room74",
		"leave"     : "/open/clan/red_fire/room/room61.c",
	]) );
	set( "build", 11015 );
	set( "long", @LONG
一走到这理....哈哈哈....$HIM$大饭店$NOR$耶！！等了好久的饭店终于完成了
，这是$HIR$爱玫$NOR$教主引进未来最新的$HIR$建$HIG$筑$HIY$科$HIB$技$NOR$完成的高级住宅区，供大家暂时
休息的好地方，不过听说里面的房间虽然很多，但是教主已说明了，$HIC$自己
要住的房间要自己布置$NOR$....否则空有房间是不行的喔！！


LONG);
	setup();
	replace_program(ROOM);
}
