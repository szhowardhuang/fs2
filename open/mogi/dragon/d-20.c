//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIC"迎风台上"NOR);
  set ("long", @LONG
冒着阵阵强风的袭卷 ,你艰辛的爬上一片高地。但
迎面而来的狂风令你连眼睛都难以睁开 ,在呼啸的风
生之中 ,感到自己的渺小..

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "westdown" : __DIR__"d-19",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}


