// open/killer/ninja/find/r7a.c
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "����̽��");
  set ("long", @LONG
  �������������һ����ȥ���Ͼ���һ�е�һ�ж��Ѿ�����������֮�⡣
  �����������Ȼ����������֮�⣬����һ����Ӱ�۽����٣�
  ����ͬʱ����һ���������������ׯ����!!��������ƺ��ǡ�ħ��ɱ����
  ����Ч���ƺ��н�Ȼ��ͬ�ĸо�����Ϊ����ͬʱ�㿴��ׯ���ᱻ������Χ!
  ǿ�����������ׯ����������������Ѫ��������ѩ�����ϣ�������Ⱦ��...
  �����̽������ϵ���Ѫ�սᣬ�����ǹ�����޷�ĥ��ĺ�ɫ.....
  ������....��......������ׯ������Ϊ�ǶȵĹ�ϵ������Ϊ���ٹ�������
  ����¶�����˵������ƺ��޷����Ų��پ�Ȼ�ṥ������
  �����⽻��֮�£��������Ѿ����˹�ȥ.....����������ȥ���ͱ���ס��
  ���㵽���ڸ���...��Ȼ���˼Ҵ򲻻��֣������������Ų��١�
  ������ʱ��Ż�������һ�ۣ���ʦ��....�������ƺ����˹��أ��е�֧�ֲ���ȥ��
  ����������Ҫ׷��ʱ�������Ѿ��������ӵ�����.....
  �������ʱ��...��!������˳��һ���������ٳ�����ɭ�����ȥ��
  
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "����ȥ" : "����Ĺ�ȥ....����Ҫ�Լ�ȥ̽��\n",
  "��ԭ�ص�" : "����Ĺ�ȥ....����Ҫ�Լ�ȥ̽��\n",]));
   
  set("exits", ([ /* sizeof() == 1   */
     "��ԭ�ص�" : __DIR__"rx9.c",
     "����ȥ" : __DIR__"r8a.c",      ]));
  set("no_transmit",2);
  setup();
}