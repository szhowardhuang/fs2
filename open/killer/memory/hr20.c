#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "Ī�����ٲ�");
  set ("long", @LONG
	
	��ɽ�ϣ�����ֱй��������ǰ�������ɷ��٣����ڶ��£���
	����ǧ������֮�ƣ�¡¡֮���������ȣ�ֻ�������������泩��
	����ǧ�ˬ���쳣������Ѽ������㲻���������Х��������
	��˾޴���ٲ�����Ȼ�������������£��ض�������ǡ�
	����һ���и�����ɽ������������㣬�����̤��Щ��������¶�ȥ��

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr19.c",   
     "down" : __DIR__"lk1.c",   
]));

  setup();
}