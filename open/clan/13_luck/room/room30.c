inherit ROOM;
void create() {
	set( "short", "港口" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room31",
		"enter"     : "/open/clan/13_luck/room/room29.c",
	]) );
	set( "long", @LONG

    这里是可以搭船去日郡的唯一水路，港口边停了几艘小船，妳向
船家租了一艘船，一个人自由自在的漂泊在海上，吹着凉凉的海风，
哇！！是多么浪漫惬意的事，当妳准备要启程时，你看了看海面上的
波浪，发现似乎好像有一定的规律，妳猜想着难道这片海有被下过阵
法。

LONG);
	setup();
	replace_program(ROOM);
}
