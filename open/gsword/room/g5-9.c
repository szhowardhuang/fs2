// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�ɽ��ɵĴ��ȣ��������ڸ����ã������ǽ�������ǵ����ɽ��ɵ�
��ɽ��ʦ����ң�ӡ���սȺħ���龰��������ʦү����Ʈ����һֻľ����
���о���ʹ����˻�Բ���⣬�����������������ұ����ɽ��ɵ�������

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g5-8.c",
  "east" : "/open/gsword/room/g5-13.c",
]));

  set("light_up", 1);

  setup();
}