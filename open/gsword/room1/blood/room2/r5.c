
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "Ѫħ����¥");
  set ("long", @LONG
�˵�ΪѪħ����¥������Խ��Խ�ӽ�Ѫħ���ǣ��ʵ��ϲк�
Ҳ��һ¥������࣬�ɼ������ս֮��״��

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room1/blood/room2/r10.c",
  "south" : "/open/gsword/room1/blood/room2/r2.c",
  "east" : "/open/gsword/room1/blood/room2/r6.c",
  "west" : "/open/gsword/room1/blood/room2/r4.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}