inherit ROOM;
void create() {
	set( "short", "又小又软的办公室" );
	set( "owner", "microsoft" );
	set( "object", ([
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/main/obj/et_sword",
		"amount3"  : 2,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount6"  : 10,
		"amount7"  : 30,
		"amount10" : 1,
		"file9"    : "/open/main/obj/et_sword",
		"amount8"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount9"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
	]) );
	set( "build", 10809 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room8",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
这里是又小又软的办公室，里面只摆了一张小桌子和椅子，桌上东西乱七八糟，
看来他似乎是个很随便的人。你四处晃晃，最后发现这里根本不是他办公的地方，
因为他忙得很，整天为了帮派的事情努力奋斗，对于他来说，办公室只是个装饰品罢了。
一想到这里，你不禁觉得这个伟大的人真是你应该效法的对象啊!!!

LONG);
	setup();
	replace_program(ROOM);
}
