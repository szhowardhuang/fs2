// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIY"∞Àÿ‘”Œ¡˙√‘’Û"NOR);

long = "\n"+
"                         "+BCYN"                      \n"NOR+
"                       "+BYEL"                      "+BCYN"    \n"NOR+
"                     "+BYEL"                          "+BCYN"    \n"NOR+
"                    "+BYEL"                            "+BCYN"    \n"NOR+
"                   "+BYEL"                              "+BCYN"    \n"NOR+
"                  "+BYEL"             "+HIY"÷––È"+HIW"(n)"+"            "+BCYN"[4~   \n"NOR+
"                  "+BYEL"            "+HIY" £ﬂ°°£ﬂ"+"             "+BCYN"   \n"NOR+
"                  "+BYEL"     "+HIY"…œ»±"+HIW"(w)"+HIY" £ﬂ°°£ﬂ"+" —ˆ√œ"HIW"(e)"
+"     "+BCYN"   \n"NOR+
"                  "+BYEL"            "+HIY" £ﬂ£ﬂ£ﬂ"+"             "+BCYN"   \n[4~"NOR+
"                  "+BYEL"                                "+BCYN"   \n"NOR+
"                  "+BYEL"             "+HIY"∏≤ÕÎ"+HIW"(s)"+"            "+BCYN"   \n"NOR+
"                   "+BYEL"                              "+BCYN"   \n"NOR+
"                    "+BYEL"                            "+BCYN"   \n"NOR+
"                     "+BYEL"                          "+BCYN"   \n"NOR+
"                       "+BYEL"                      \n"NOR+
"\n";

set("long", long);
set("exits", ([
      "east"  : __DIR__"r9",
      "west"  : __DIR__"r4",
      "south" : __DIR__"r5",
      "north" : __DIR__"r7",
  ]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("no_clean_up", 1);
          call_other("/obj/board/night_b", "???");
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
        tell_object(who,"”…”⁄¥À¥¶¥≈≥°π˝«ø£¨ƒ„µƒªΩ‘∆…»Œﬁ∑®…Ë∂®°£\n");

        return 1;
}
