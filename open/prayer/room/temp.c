//open/prayer/room/punch1-2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛大听");
  set ("long", @LONG

    这是圣火教的总坛大厅，帮务处理与玩家讨论的地方，你可以在这留
下你对圣火教的建议，或是圣火教哪出了问题，都可以在此留言，毕竟圣
火教是为大家而开的，请大家好好爱惜它。

LONG);

  set("exits", ([ /* sizeof() == 4 */
          "south" : "/open/main/room/maiu-1",
]));
  set("light_up", 1);
  setup();
    call_other("/obj/board/prayertemp_b","???");
}
 
