inherit ROOM;
void create() {
	set( "short", "��¥�ߵ�" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room224",
		"up"        : "/open/clan/13_luck/room/room222",
	]) );
	set( "long", @LONG

������С���������������֮�У������ʯ�����м�������ͬһ����
�ӣ�һ��С�ľͻ���ʧ���У�������С���ǲ����ˣ����������ҹ���
��С��������ǰ����ǰ��֮ʱ��ͻȻ�ĵ�Ӱ�����㸩���������ס��
��ȥ·������һ������ڡ���Ȼ�Ǽ�������

LONG);
	setup();
	replace_program(ROOM);
}