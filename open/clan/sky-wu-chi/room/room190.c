inherit ROOM;
void create() {
	set( "short", "沁芳亭" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/main/obj/firesword",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"file3"    : "/open/ping/obj/fan-1",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
	]) );
	set( "build", 10140 );
	set( "owner", "jsa" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room200.c",
		"north"     : "/open/clan/sky-wu-chi/room/room216",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
面对一池莲花的八角亭子，琉璃瓦的飞檐依天光云
影变幻着色泽，八柱子下设有矮栏以供坐落，相榇之下
显得热闹又不落俗套；亭中置圆形石桌与圆椅，皆覆以
四方布以隔石寒气，待仲夏夜中水殿风来，于此小坐片
刻，不觉暑气全消心旷神怡。
LONG);
	setup();
	replace_program(ROOM);
}
