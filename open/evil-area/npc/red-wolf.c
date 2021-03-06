#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create() 
{
        set_name(HIR"赤身红狼"NOR,({"red-wolf","wolf"}));
        set("long",
            "\n火红色的狼，似乎正象征着他那凶猛的个性。\n");
        set("age",13);
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",5000);
        set("max_kee",5000);
        set("max_sen",5000);
        set("max_force",50000);
        set("force",2000);
        set("force_factor",10);
        set("combat_exp",400000);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("parry",200);
        set("limbs",({"头部","胸部","前肢","后肢","腰部"}));
        set("verbs",({"bite","claw"}));
        setup();
}

void heart_beat()
{
	object ob,env,target;
	int sk1,sk2;

	ob = this_object();
	env = environment(ob);
	if(random(100) < 30)
	{
    	target = offensive_target(ob);
	sk1 = (int)ob->query_skill("parry");
	sk2 = (int)target->query_skill("parry");
		if( env == environment(target) && random(sk1) > random(sk2))
		{
                message_vision("
\n$N"HIR"口中喷出一道火红色的烟雾，$n不慎吸入一点，顿时全身发烫。\n\n"NOR,ob,target);
                target->receive_damage("kee",200);
                COMBAT_D->report_status(target,1);
		}
	}
set_heart_beat(1);
::heart_beat();
}

void die()
{
object me,ob,obj;
        ob = this_object();
        me = ob->query_temp("last_damage_from");
        if( random(100) < 50 && me->query_temp("evil/g_temp/ask") && !me->query_temp("evil/g_temp/get"))
        {
                message_vision(HIY"\n$N趁着$n不注意之时，狠狠的咬住$n，随即转身跑掉!!\n"NOR,ob,me);
                me->receive_damage("kee",200);
                COMBAT_D->report_status(me,1);
                tell_object(me,HIY"\n\n你得到了一颗赤身狼牙。\n"NOR);
		obj=new(__DIR__"obj/tooth");
		obj->move(me);
		me->set_temp("evil/g_temp/get",1);
                destruct(ob);
        }
::die();
}

