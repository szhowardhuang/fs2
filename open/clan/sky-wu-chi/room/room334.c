inherit ROOM;
void create() {
	set( "short", "空瓶子招待所5" );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room335",
		"east"      : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
这里是属于要谈机密的地方,而四周看起来就像是一个练武场
原来是空瓶子喜欢以武会友,顺便说三道四的,所以一些高阶的
朋友都在这边谈论事情,但是呢,为了必免有人偷听,所以空瓶子
就想出一个妙计,使用了八成功力在这里做一个防护结界
任何人在这里面只能用say 而传不出去声音..
也许是因为有太多秘密的关系了...
LONG);
	setup();
	replace_program(ROOM);
}
