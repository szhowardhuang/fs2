inherit ROOM;
void create() {
	set( "short", "���⺣��" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room52.c",
		"north"     : "/open/clan/13_luck/room/room49",
		"south"     : "/open/clan/13_luck/room/room37",
		"east"      : "/open/clan/13_luck/room/room48.c",
	]) );
	set( "long", @LONG

    ����������ȥ�������ܿ�����Զ�ĵط���Ҳ�ƺ�������½�أ�ֻ
����һ��Ƭ�������󺣣�����С�Ƴ���С�ˣ����˵����͡���������
��֪�����ķ���Բ��ԣ�����Զ����ȥ���ǿ������κ�һ��յأ���
�������ǲ�����·�ˡ�

LONG);
	setup();
	replace_program(ROOM);
}