inherit ROOM;
void create() {
	set( "short", "������" );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room312",
	]) );
	set( "long", @LONG
������������������������������������������������
������������������������������������������������
������������������������������������������������
������������������������������������������������
��[1;36m������ʥ[1;37m��ʮ���鶯��[0m[1;33m��������[0m(Fly_man)
LONG);
	setup();
	replace_program(ROOM);
}
