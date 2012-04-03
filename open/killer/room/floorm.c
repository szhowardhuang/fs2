#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "楼梯间");
  set("long", @LONG
  两旁的灯火顺着楼梯一直往上去，似乎通往的极为重要的地方。
  我想没事最好不要乱闯，但是你是否能克制自己的好奇心呢？
  楼梯旁似乎有往北方的通道，里面杀声连连，令你不禁想一探究竟。
  西方传来阵阵的药味与奇怪的味道，似乎人声鼎沸。
  东方是杀手们的起居地有饭厅与宿舍，需要的人可以去看看。
LONG);
    set("light_up", 10);
   set("exits", ([
   "north": __DIR__"boardrm.c",
    "west": __DIR__"r19",
    "east": __DIR__"r18.c",
      "up": __DIR__"ru0.c",
   "south": __DIR__"r17.c",
    ]));
   set("objects",([
         "/open/killer/npc/guard.c":  2,
           ]));
 setup();
}