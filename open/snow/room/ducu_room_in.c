#include <room.h>

inherit ROOM;

void create()
{
	set("short","����������");
          set("long",@LONG
������Ƕ���������ã����������ݵ�����ѩ���ɵ��������Ŷ��³��Ž�
����תа�ơ����ഫ��ʮ��ǰ�����³����������Ĵ����֮һ�����ɽ��ɵ�֣ʿ��
��ħ��Ī�⣬�����ŵ�һ������ǧ�����˲��У����³������ֵ�ѩ�Թ�Ӱ�ż�����
��֮��Ӱ���ٲ�����������֡�������֮��������λ�Ե��Ƕ��³���ǰ������ʫ
�䣬ʫ����д�ţ�
      
          ��������������У��κϼ���������
 
                          ���ĺ���ʱ��������֪�����޳
 
 
LONG);
        set("exits", ([
	"east":__DIR__"ducu_room",
	"west":__DIR__"ducu_room_in1",
	"north":__DIR__"ducu_live",
        ]) );
	set("light_up",1);
        setup();
}