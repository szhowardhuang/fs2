inherit ROOM;
void create() {
	set( "short", "夏雷书房" );
	set( "owner", "roboo" );
	set( "object", ([
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/open/tendo/obj/chaosbelt",
		"file2"    : "/daemon/class/fighter/armband",
		"amount7"  : 1,
		"file10"   : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10011 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room69",
		"north"     : "/open/clan/sky-wu-chi/room/room347",
	]) );
	set( "long", @LONG
    在这里的墙上的书架上摆满了数不尽的各式书籍，只要是市面上 
有的任何书籍，这里一本不缺，除此之外，一些早已绝版找不到着古 
书籍也能在这儿找到。夏雷让他的两个人物在此唸书，盼望他们两  
能博学多识，而那两个因一人擅文一人擅武，所读之书亦彼此不同 
，不过看他们专注认真的神情，将来势必能有一番作为。 
LONG);
	setup();
	replace_program(ROOM);
}
