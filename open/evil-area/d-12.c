inherit ROOM;

void create()
{
        set("short","ʬ�ǵ�");
        set("long",@LONG
���Ľ�������ʬ�����ѻ����ɵĵ�·��ÿһ����ͷ����״��һ��
��֪������һ�������Ǽܣ�������������ϸ���ƺ󣬷��ֵ�ÿһ��
��ͷ���涼�в�ͬ���˺ۣ��е���ץ�ۣ��е���ҧ�ۣ��е����Ѻۣ�
�����ڻ���ʮ������ĵ��ۣ��������������а������ʬ��������
��ȥ���ƺ���һ�����ҵ��ڲ�Զ���Ϸ����������ǽ���ɳĮ�ڡ�
LONG);
        set("exits",([
"south":__DIR__"d-10",
]));
        set("objects",([
__DIR__"npc/mob1":1,
__DIR__"npc/mob3":2,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}