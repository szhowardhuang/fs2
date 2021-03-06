inherit ROOM;
void create() {
	set( "short", "寒霜居-大厅" );
	set( "light_up", 1 );
	set( "owner", "roboo" );
	set( "build", 10182 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room206",
		"east"      : "/open/clan/sky-wu-chi/room/room362.c",
		"west"      : "/open/clan/sky-wu-chi/room/room361.c",
		"south"     : "/open/clan/sky-wu-chi/room/room241.c",
	]) );
	set( "long", @LONG
虽然这座大厅跟所有的房间并没有太大的差别，一样都是由水
晶所制成的，但却比任何一个房间要大的许多。向天花板看去可以
看到由水晶所组成的龙型浮雕，其微妙为俏的程度令你怀疑那个龙
型浮雕是否会向你袭击。向两边看去可以看到两间大门紧闭的房间
，西边的房间上方的匾额写着｛练功房｝，你感觉到从西边的房间
隐隐散发出一种来自天地宇宙间的神秘而且压迫的感觉，令你犹豫
着是否应该入内一探究竟。而东边的房间上的匾额则写着｛藏经阁
｝，看来在这房间中似乎有着武林人士所争相追求的秘笈宝典吧。
LONG);
	setup();
	replace_program(ROOM);
}
