#include <room.h>

inherit ROOM;

void create()
{
	set("short","����");
          set("long",@LONG
������ѩ���ɵ���������ͷ��װ�ο�������һ����ʷ�ˣ�����
������ѩ���ɵĸ��ݵأ�����Ľ��������ٶ��꣬�ഫѩ����
��ɽ��ʦ���꿪��ʱ�ƺ��н���һЩ��������֮��ġ�
LONG);
        set("exits", ([
	"east":__DIR__"room2",
	"west":__DIR__"room11",
        ]) );
	set("light_up",1);
        setup();
}