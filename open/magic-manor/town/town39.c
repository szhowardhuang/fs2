inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "�Ʒ綫��");
        set ("long", @LONG
�ߵ�������������һ�������ĵط�����Զ������������С��
�����������ߵ������ε�������࣬�������˳�Ҳ�����Ķ��ˣ�����
��һ����ů�ĸо��������������֣��Ǵ��������ȥ�ĵط�����Ϊ��
����������߽�ȥ֮�����Ҳ�������ˣ����Զ��������Ľ��롣
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town42",
        "west"	: __DIR__"town24",
	]));

        setup();
}