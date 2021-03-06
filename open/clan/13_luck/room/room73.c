inherit ROOM;
void create() {
	set( "short", "天仁中医诊所" );
	set( "owner", "force" );
	set( "object", ([
		"amount8"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10023 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room71",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你看到大厅上方挂着一个匾额，提着四个斗大的字〔$HIR$妙手回春$NOR$〕，
你不禁暗自猜想，这间诊所的医生应该是个$HIW$狠角色$NOR$，你走近左边，
墙上满布着奖状，都是称赞医生的医术高超，此外，还挂着一张$HIC$价
目表$NOR$，上面写着：
　　　　　　$HIW$没毒　１０００　ｄｉａｍｏｎｄｓ
　　　　　　零病　１０００　ｄｉａｍｏｎｄｓ
　　　　　　肾亏　９９９９　ｄｉａｍｏｎｄｓ$NOR$

你看着$HIC$价目表$NOR$，想了想，觉得这家根本是$HIR$黑店$NOR$，于是你决定去别家
医院。

LONG);
	setup();
	replace_program(ROOM);
}
