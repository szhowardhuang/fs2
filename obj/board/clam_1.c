#include <ansi.h>
inherit BULLETIN_BOARD;

#include <ansi.h>
void create()
{
  set_name(HIC"风雷帮的帮派讨论区"NOR, ({"board"}));
  set("location","/open/clam/wind.c");
   set("board_id","clam_1");
  set("long","
   风雷帮 帮众 , 大家集合啰~~~~~\n
  有事大家一起帮忙吧");
    setup();
    set("capacity", 50);
}
