#include <ansi.h>
 

inherit NPC;

void create()
{
	set_name("杀手" ,({"assassin"} ));
	set("gender", "男性");
	set("long","
一个杀手在这里徘回，不知他为了甚么目的来到此地。\n");
    
	set_skill("dodge", 50);
	set("age",27);
	set("max_sen",300);
	set("max_gin",310);
	set("attitude", "peaceful");
	set_skill("unarmed",10);
	set("max_kee",350);
	set("combat_exp",100000);
	set_temp("apply/armor",20);

	set_temp("apply/dodge",15);
	set("chat_chance_combat", 60);
	set("chat_msg_combat" ,({
	(: this_object(),"special_att" :),
}) );
	setup();
	carry_object("/open/poison/obj/bcloth.c")->wear();
	carry_object("/open/poison/obj/ball.c")->wield();
	add_money("silver",3);
	
}
int special_att()
{
	object ob=this_object()->query_enemy();
	if(ob->query("family/family_name")!="冥蛊魔教")
	{
message_vision("杀手冷不防的抽出一把蓝森森的匕首，狠狠的捅了$N一下。\n",ob);
 
	ob->apply_condition("snake_poison",1);
	return 1;
	}
}
void greeting(object me)
{
	if( me->query("family/family_name")=="金刀门")
	{ command("say 金刀门的家伙! 受死吧!");
	kill_ob(me);
	}
	
}
