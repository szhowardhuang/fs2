// For the new hand of dancer ...//purple
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("妙龄少女",({"cutegirl"}) );
  set("title", "夜梦小筑见习生");
  set("gender", "女性");
  set("age",13);
  set("attitude", "heroism");
  set("long", "在夜梦小筑修业满一年，将成为月牙儿徒弟的见习生\n");
  set("kee",2000);
  set("max_kee",2000);
  set("max_force",600);
  set("force",600);
  set("combat_exp",5500);
  setup();
}