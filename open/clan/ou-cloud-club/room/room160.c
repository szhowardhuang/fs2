inherit ROOM;
void create() {
	set( "short", "$HIR$藏$NOR$Φ$HIY$妖幻护膝$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "light_up", 1 );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room205.c",
		"out"       : "/open/clan/ou-cloud-club/room/room264",
	]) );
	set( "long", @LONG
强烈的腐蚀妖气朝着你迎面扑来，使你不得不运起全力抵挡这吞噬生命
的惊人杀气，这里封印的神器，原本属于背叛天界，堕落至凡间的千年树妖
--舞风扬所有，当他于千年前败于天将之后，遭妖魂遗弃的肉身，被众神调
制成为十二神器中少数具有妖气的绝世装备．

LONG);
	setup();
	replace_program(ROOM);
}
