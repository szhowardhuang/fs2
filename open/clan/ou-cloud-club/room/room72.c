// Room : /open/clan/ou-cloud-club/room/room72.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
һ���������ߵĵ�·����ȥ���಻����������㡡��������
һ�߿����������ף����Ժ��������㣬�ʴ˴������ѡ���������
�����������ѣ����ڴ˴��⵽��������ǰ��ɻ����ѡ���������
���мܣ�����������������
����������
LONG);
	set( "short", "$HIY$��ɽ$NOR$��" );
	set( "clan_room", "����ɽׯ" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "up" : "/open/clan/ou-cloud-club/room/room73.c",
  "down" : "/open/clan/ou-cloud-club/room/room71",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}