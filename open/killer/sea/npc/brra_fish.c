#include <ansi.h>
#include </open/open.h>
inherit NPC;
void create()
{
set_name("巴拉金梭鱼",({"barracuda"}));
set("long","这是什么鱼呀？看来海中生物种类还是真多耶........n");
set("race","人类");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "头部", "身体",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",20);
set("int",30);
set("per",30);
set("str", 35);
set("con", 30);
set("force",500);
set("max_force",500);
set("max_kee",1500);
set("kee",1500);
set("combat_exp", 5000);
setup();
}