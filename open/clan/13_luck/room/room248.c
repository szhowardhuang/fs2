inherit ROOM;
void create() {
	set( "short", "��ʯ��С·��" );
	set( "light_up", 1 );
	set( "owner", "poll" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room249",
	]) );
	set( "long", @LONG
������ɽ��������������Ȼ���ۣ������ڹ���Ϣ����ȴ�о�������ˡ�
����ƽ����ʱ�̣����ķ���ȥ��ֻ����ز�����ŵ��£���������ؿ�����
���࣬ʹ����ԭ��������׳־�����ӵļᶨ�ˡ��������Ա��и����ˣ�����
���ƺ�����ô����������Ҳ������߿��羰�İɡ������߿���ȥ�������и�
��ͤ���������������˶������Ǹ���ͤ����һ�£����Լ��ľ���ظ���
LONG);
	setup();
	replace_program(ROOM);
}