#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "山林区");
  set ("long", @LONG

   巨大的林木，使得视野并不是很宽广，但是仍然可以轻易的行走于其间
   但是树林之间似乎总是有人在窥探着你，难道是隐身于其间的杀手？
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   */
     "northeast" : __DIR__"hr3.c",
     "westsouth" : __DIR__"hr1.c",   
]));
  set("objects",([
  "/open/killer/npc/spy4.c":1,]));
  setup();
}
