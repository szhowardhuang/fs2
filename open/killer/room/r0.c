#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "专业杀手训练室");
  set("long", @LONG
  这里有一系列的训练课程，由初级到高级，应有尽有。
  在一楼的是初级班，适合新进杀手拿匕首练习。
  在二楼的是高级班，一般新进杀手可不要乱闯。

LONG);
    set("light_up", 10);
   set("exits", ([
   "north": __DIR__"waterm.c",
    "west": __DIR__"r12",
    "east": __DIR__"r11.c",
      "up": __DIR__"r0u.c",
   "south": __DIR__"boardrm.c",
    ]));
   set("objects",([
         "/open/killer/npc/train_d.c":  3,
           ]));
 setup();
}