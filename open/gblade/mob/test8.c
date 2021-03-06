// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{

        set_name("铜剑战士",({"soldier"}));
        set("long","一个英资勃勃的战士 , 佩带一把青铜剑 \n");

        set("age", 28);

        set("str", 40);
        set("no_exp",1);
        set("cor", 30);
        set("cps", 25);
        set("force",300);
        set("max_force",300);
        set("force_factor",3);

        set("combat_exp", 30000);
/*
        set("chat_chance", 15);
*/
         set_skill("parry", 35);
        set_skill("dodge", 20);
        set_skill("sword",40);
        set_skill("shasword",40);
        set_skill("sha-steps",30);
        map_skill("sword","shasword");
        map_skill("dodge","sha-steps");

        setup();
        carry_object("/open/gsword/obj/sword.c")->wield();

}



void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIW"一个雄威懔懔的战士从妖壶中走出 .\n"
        + name() + "说道 : 找死 !\n"NOR,
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
