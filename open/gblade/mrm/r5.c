inherit ROOM;
 
void create ()
{
  set ("short", "ħ����");
  set ("long", @LONG

������ħ�����ĵ�һ�㣬һ̤��������ܵ�ɱ��ͻȻŨ����������һ
˫˫����ɱ�����۾����������㡣�㶨�˶����ע�⵽����������
�ܣ����������ŵ��ۣ����䴦����һ�Ѷѵĺ��ǣ�ʹ�㲻�����ݡ�

LONG);
set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r4.c",
  "east" : __DIR__"r6.c",
]));
set("objects",([
"/daemon/class/blademan/npc/corpse1.c":3,
]));
  setup();
  replace_program(ROOM);
}