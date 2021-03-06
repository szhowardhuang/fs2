inherit ROOM;
void create() {
	set( "short", "$HIY$【$HIR$红莲 $HIM$北门$HIC$哨塔$HIY$】$NOR$" );
	set( "object", ([
		"file3"    : "/open/gblade/obj/gold-boots",
		"file7"    : "/open/capital/obj/king-cloak",
		"file6"    : "/open/capital/obj/king-ring",
		"amount2"  : 1,
		"file8"    : "/open/gblade/obj/gold-armor",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/capital/obj/king-belt",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"amount10" : 7,
		"file1"    : "/open/capital/obj/king-cloth",
		"amount7"  : 1,
		"file9"    : "/open/killer/headkill/obj/f_dag",
		"amount1"  : 1,
		"file4"    : "/open/capital/obj/king-boots",
		"amount6"  : 1,
		"file2"    : "/open/gblade/obj/gold-robe",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10884 );
	set( "outdoors", "/open/clan/red_fire" );
	set( "exits", ([
		"down"      : "/open/clan/red_fire/room/room44",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
虽然北方是一大片的$YEL$沙漠$NOR$，但是因为之前前往$BLU$遗迹$NOR$的$HIY$采金客，$NOR$走不出
这$YEL$沙漠$NOR$，而当了杀人不眨眼的$YEL$沙漠$WHT$土匪$NOR$，教主为了防止他们的入侵，在此
派人守备，以免$WHT$土匪$NOR$的袭击。


LONG);
	setup();
	replace_program(ROOM);
}
