inherit ROOM;
#include <way.c>

void create()
{
	set("short","��կ ������");
	set("long",@LONG
����һ�����С���ܱտռ䣬����Կ�����������һ�����͵�
���Σ��������˵����կկ�����������ƺ����Ե��е�С���������
��������Ļƽ����鱦�����������Ƿ��ñ���ĵط���
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/snake_soldier":1,
"/obj/money/silver":10,
]));
	set("exits",([
"west":__DIR__"r-19",
"south":__DIR__"r-17",
]));
	setup();
}