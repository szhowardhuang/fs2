#include <ansi.h>
inherit NPC;
void create ()
{
  set_name("船员",({"ship member","member","ship"}));
  set("long","商船上的人员, 身材魁武, 看起来十分精明能干!!\n");
  setup();
}
