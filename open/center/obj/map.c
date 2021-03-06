#include <ansi.h>

inherit BOOK;

#define BOOK_PATH "/open/center/obj/"
#define BOOK_NAME "map"
#define BOOK_NAME1 "map1"
#define C_BOOK_NAME "主大陆地图"

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "map" }) );
  set( "long", "这是一张由前辈高手冒险的心血所绘制的地图。\n");
  
  // set ( "value", ({ 10, "silver" }) );
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

int do_read(string arg)
{
  object me=this_player();
  int   query1, query2;

  query1 = me->query_temp("quests/badman_license");
  query2 = me->query_temp("quests/help_water_god");
  if (query1 == 2 || query2 == 2) {
    if (query1 == 2) me->set_temp("quests/badman_license", 3);
    if (query2 == 2) me->set_temp("quests/help_water_god", 3);
    set ( "book_path", BOOK_PATH + BOOK_NAME1 );
    if (::do_read(arg)) {
      write (HIY"当你仔细看完地图时，发现有一个地方怪怪的，"+
             "值得去看一看，也许那儿正是哭风坡。\n"NOR);
      return 1;
    }
    else return 0;
  }
  else
    return ::do_read(arg);
}
