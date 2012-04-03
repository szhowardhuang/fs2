//皇城禁卫军

#include </open/capital/capital.h>

inherit NPC;

void create()
{
        set_name("皇宫禁卫军",({"castle soldier","soldier"}) );
	set("gender","男性");
	set("age",25);
	set("class","soldier");
	set("str",30);
	set("long","皇城禁卫军是保卫皇宫的先锋, 均为万中选一的精英。\n");

	set("combat_exp",75000);
	set_skill("blade",50);
	set_skill("parry",50);
	set_skill("dodge",50);
        set_skill("her-blade",40);
        map_skill("blade","her-blade");
	setup();
        carry_object(CAP_OBJ"Hblade")->wield();
	carry_object(CAP_OBJ"Ns_boots")->wear();
	carry_object(CAP_OBJ"carmor")->wear();
	carry_object(CAP_OBJ"ironshield")->wear();
	carry_object(CAP_OBJ"ironarmband")->wear();
		
}


int accept_fight(object who)
{
	return notify_fail(query("name")+"说：放肆!!\n");
}
