inherit ROOM;
void create() {
	set( "short", "$HIC$【$HIW$秘密药房$HIC$】$HIW$小新$NOR$" );
	set( "owner", "mudu" );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room24",
	]) );
	set( "long", @LONG
在这房间里所放的是小新难得的天人圣药，吃了不但
提神补气，更能起死回生，站在一旁的小弟，本来弱小不
禁风雨，但吃了一个小小的药丸后，变得身体力壮。。。
找一找私乎能找到许多不常看到的东西。。。一旁的不是
男人的圣品吗。。。

LONG);
	setup();
	replace_program(ROOM);
}
