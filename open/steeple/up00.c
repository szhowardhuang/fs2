inherit ROOM;
#include <ansi.h>
void create()
{
set("short","������һ¥");
set("long",@LONG

��������֮������򵥵�һ��¥�����治�����һ�Ѱ�è������
����Ӧ���Ǻܼ򵥾���ͨ���ˡ�

LONG);
set("exits",([
"up":__DIR__"busy_room01",
"out":__DIR__"ticket",
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("objects",([
__DIR__"obj/npc/npc01":1,
]));
setup();
}

int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<=1)
{
tell_object(me,HIR"ϵͳ����ľ�Ƭ���ϲ�����ͨ��¥�ϡ�\n"NOR);
return 0;
}
{
message_vision(HIW"ϵͳ����ȡ"+me->query("name")+"����Ƭ��ͨ����\n"NOR,me);
return 1;
}
}
if(dir=="out")
return 1;
}