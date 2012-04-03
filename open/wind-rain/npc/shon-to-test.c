inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
	set_name("项拓",({"shon-to","to"}));
        set("title","掩光天卫");
	set("long","
他是守护一楼楼主刁千刃的
三大护卫之一, 虽长刁千刃
二十载, 服侍忠心不二, 是
刁千刃最信任的人.
");
	set("gender","男性");
	set("combat_exp",9000000);
	set("attitude","peaceful");
	set("age",50);
	set("class","soldier");
	set("str", 30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
         set("max_force",25000);
         set("force",25000);
         set("max_kee",25000);
	set_skill("blade",100);
        set_skill("golden-blade",100);
	set_skill("parry",100);
        set_skill("wind-rain",75);
	set_skill("dodge",100);
        set_skill("move",70);
        set_skill("lo-steps",80);
        map_skill("blade", "golden-blade");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");
	setup();
        carry_object(C_OBJ"/three-star-blade")->wield();
	add_money("silver",90);
}
int accept_kill(object who)
{
  command("say 竟敢动风雨楼的人！");
  return 1;
}
