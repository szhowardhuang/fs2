//test1

#include <ansi.h>

inherit NPC;

void create()
{

        set_name("小狗",({"dog"}));
        set("long","一只小狗 , 看起来蛮欠揍的 !");
        set("race","野兽");

        set("max_gin", 50);
        set("max_kee", 50);
        set("max_sen", 50);

        set("age", 5);

        set("str",20);
        set("cor", 30);
        set("cps", 25);
        set("no_exp",1);

        set("limbs",({"头部","前脚","尾巴","身体"}));
        set("verbs",({"bite","claw"}));
        set("combat_exp", 1);
/*
        set("chat_chance", 15);
*/
        setup();

}



void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIY"一只小狗从妖壶中窜了出来 .\n"
        + name() + "汪汪的叫了两声!\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        /*
        set_leader(who);
        */
}
