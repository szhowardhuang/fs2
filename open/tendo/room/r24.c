// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIG"八卦游龙迷阵"NOR);

long = "\n"+
"                         "+BRED"                      \n"NOR+
"                       "+BMAG"                      "+BRED"    \n"NOR+
"                     "+BMAG"                          "+BRED"    \n"NOR+
"                    "+BMAG"                            "+BRED"    \n"NOR+
"                   "+BMAG"                              "+BRED"    \n"NOR+
"                  "+BMAG"             "+WHT"天象"+HIW"(n)"+"            "+BRED"   \n"NOR+
"                  "+BMAG"            "+WHT" ＿　＿"+"             "+BRED"   \n"NOR+
"                  "+BMAG"     "+WHT"风象"+HIW"(w)"NOR+BMAG+WHT" ＿　＿"+" 火象"
HIW"(e)"+"     "+BRED"   \n"NOR+
"                  "+BMAG"            "+WHT" ＿　＿"+"             "+BRED"   \n"NOR+
"                  "+BMAG"                                "+BRED"   \n"NOR+
"                  "+BMAG"             "+WHT"地象"+HIW"(s)"+"            "+BRED"   \n"NOR+
"                   "+BMAG"                              "+BRED"   \n"NOR+
"                    "+BMAG"                            "+BRED"   \n"NOR+
"                     "+BMAG"                          "+BRED"   \n"NOR+
"                       "+BMAG"                      \n"NOR+
"\n";

set("long", long);
set("exits", ([
      "east"  : __DIR__"r1",
      "west"  : __DIR__"r1",
      "south" : __DIR__"r25",
       "north" : __DIR__"r1",
  ]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("no_fanset","fanset");
}

int no_fanset()
{
        object who;
        who = this_player();
        tell_object(who,"由于此处磁场过强，你的唤云扇无法设定。\n");

        return 1;
}
