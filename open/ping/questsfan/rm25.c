// Room: /u/d/dhk/questsfan/rm25
inherit ROOM;
#include <ansi.h>
#include </open/open.h>
void create ()
{
  set ("short", ""HIY"望"HIC"星"WHT"坪"NOR"");
  set ("long", @LONG
穿过潮湿的＂日日甘霖″来到一处高地，名曰‘望星坪’。因为
每当月兔西升时，这里就成了最佳观星赏月地。当我们向东南方向望
过去时发现，那片山壁被人用利器在那片广大平滑的山壁上题了数个
大字。～‘名山之世，世间仙境，境冠群岳’～

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rm11",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=1 && who->query_temp("mime")==1)
    {
     tell_object(who,"\n"WHT"忽然一道黑色的人影快速往西边离去，身形之快匪夷所思。"NOR"\n");
       who->set_temp("run",1);
     remove_call_out("dhk");
    }
}

