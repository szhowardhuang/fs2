// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","����");
set ("long", @LONG
�߷����ף��������ϣ�ֻ��������ݣ�����ǣ�ٵģ����������ģ�
��ʯ�Ż�����ˣ����������������������͡��������ڣ������
�գ����b֮ˮ���������ٸ���������Ҷ������������޵���ң���
���仪���������������һ����쳾��Ⱦ��
LONG);



  set("exits", ([
            "north"  : __DIR__"35",
            "south"  : __DIR__"33",
                ]));

   set("objects", ([ 
  __DIR__"npc/thin-guard-out" : 3,
                  ]));         

        setup();
}