#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "ͨ��С��һ¥");
  set ("long", @LONG

   ��������Ż�������Զ����������ˣ����˺�����ɵ�������
   ������ȥÿ�����䳤�Ķ�һ�����������Էֱ棬����Ҫ���ȥ���ߣ�

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "west" : __DIR__"hr7.c",
     "down" : __DIR__"hr8.c",   
     "north" : __DIR__"hr9.c",   
     "south" : __DIR__"hr15.c",   
]));

  setup();
}

void init()
{
//
}

int do_look(string str)
{
  object me;

   if(str )
    return notify_fail("���뿴ʲô����������û���˾����𣿣��ÿ޵ıȽϿ�������\n");
   return 1;
}