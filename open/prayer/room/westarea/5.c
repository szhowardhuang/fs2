//open/prayer/room/westarea/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","��ϼ��");
        set("long",@LONG

	����ɽ�ϵ�һ��Сɽ��, ��ǰ������һЩ���ӵ�é
	��, ����Щ�������Ĵ��ҷ�����!!ϼ������, ��һ
	��������Դ֮��Ϣ!!��ǰ��λ����ʥ��̸�������
	���������!!��, ������Ե���, �ǲ��Ǹ�������
	л���֮����??

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"2",	
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/high-man" : 1,		
        ]));
  setup();
}