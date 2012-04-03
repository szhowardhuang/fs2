inherit ROOM;
void create() {
	set( "short", "风云阁入口" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"file6"    : "/open/capital/obj/chen_dagger",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "owner", "smalloo" );
	set( "build", 11214 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room76.c",
		"enter"     : "/open/clan/13_luck/room/room339",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    映入你眼帘的是一幢[0;1;30m□[1m□[1m□[1mo[1m□[1m□[1m□[1m□[1m□[1mv[0m，虽然没有雕龙飞柱，但是，门
却是用[0;1;34m□[1m□[0m跟[0;1;36m□[1m□[0m两个字所做的入口而在[0;1;34m□[1m□[0m跟[0;1;36m□[1m□[0m两个字上面写这一句话，
       [0;1;5;32m□[1;5m□[1;5m [1;5m [1;5m [1;5m□[1;5m][1;5m [1;5m [1;5m [1;5m□[1;5m□[1;5m [1;5m [1;5m [1;5m□[1;5m□[0m
       [0;1;5;31m□[1;5m□[1;5m [1;5m [1;5m [1;5m□[1;5m][1;5m [1;5m [1;5m [1;5m□[1;5m□[1;5m [1;5m [1;5m [1;5m□[1;5m□[0m
 
屹立于一大片旷野上，显得格外气派威武，此时微风徐徐吹来，
天上的云层也有点儿飘忽不定，令你觉的[0;1;35m□[1m□[1m□[1m□[1m□[1mq[1m□[1mM[1m□[1mC[0m


LONG);
	setup();
	replace_program(ROOM);
}
