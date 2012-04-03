inherit ROOM;
void create() {
	set( "short", "$GRN$炮阵地$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "del" );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room147.c",
		"north"     : "/open/clan/ou-cloud-club/room/room254",
		"south"     : "/open/clan/ou-cloud-club/room/room33.c",
		"west"      : "/open/clan/ou-cloud-club/room/room118.c",
	]) );
	set( "long", @LONG
这里是一片空旷的草原，绿油油的一片让人看了心旷神
怡，正前方有一块焦黑的地皮，原来那边架了一门火炮，上
面写着[1;33m‘国造六三式一二○公厘迫击炮’[0m，旁边还站了几个
身穿迷彩军服正在操练的阿兵哥。不远处有几条不知道通往
何处的深邃小径，好奇的你有点跃跃欲试想去探险的感觉。
  
  [1;37m一二○公厘迫击炮[0m(Ternch mortar)
  [1;34m迫击炮炮班班长[0m(Mortar corporal)  
  [1;36m迫击炮炮班炮手[0m(Mortar man1 - 3)
  
LONG);
	setup();
	replace_program(ROOM);
}
