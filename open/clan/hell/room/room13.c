inherit ROOM;
void create() {
	set( "short", "$HIB$阎罗王「哼”的一声，从袖中掏出一本像帐册的东西翻看着。$BLK$" );
	set( "owner", "creed" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10285 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room127",
		"east"      : "/open/clan/hell/room/room143.c",
		"south"     : "/open/clan/hell/room/room2.c",
		"west"      : "/open/clan/hell/room/room99.c",
	]) );
	set( "long", @LONG

$RED$鬼门关$NOR$ - 
    这里就是著名的阴间入口「鬼门关”，在你面前矗立着一座高大的
黑色城楼，所多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再
回阳间了。你在门前徘徊了许多，深怕一进就出不来，此时此刻。你的
神在不知觉中被拉了进去。

  阎罗王(Ghost king)
LONG);
	setup();
	replace_program(ROOM);
}
