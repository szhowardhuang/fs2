//test1

#include <ansi.h>

inherit NPC;

void create()
{

        set_name("ÃÍ»¢",({"tiger"}));
        set("long","Ò»Ö»»¨ÎÆ°ßÀ¸µÄÃÍ»¢");
        set("race","Ò°ÊÞ");

        set("max_gin", 250);
        set("max_kee", 400);
        set("max_sen", 250);
        set("no_exp",1);

        set_temp("apply/armor",10);
        set_temp("apply/damage",1);
        set_temp("apply/attack",40);
        set_temp("apply/dodge",30);
        set("age", 5);

        set("str", 40);
        set("cor", 30);
        set("cps", 25);

        set("limbs",({"Í·²¿","Ç°½Å","Î²°Í","ÉíÌå"}));
        set("verbs",({"bite","claw"}));
        set("combat_exp", 5000);
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
        HIY"Ò»Ö»¶ñ»¢´ÓÑýºøÖÐ³å³ö .\n"
        + name() + "»¢ºðÒ»Éù , Ïì³¹ÔÆÏö !\n"NOR,
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
