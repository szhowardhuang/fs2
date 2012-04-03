//皇城禁卫军

#include </open/capital/capital.h>
#include <ansi.h>

inherit NPC;
int accept_kill(object who);

void create()
{
          set_name("皇门守卫",({"soldier"}) );
        set("gender","男性");
        set("age",25);
        set("class","soldier");
        set("str",30);
        set("long","皇城禁卫军是保卫皇宫的先锋, 均为万中选一的精英。\n");

        set("combat_exp",3000000);
        set("max_gin",1000);
        set("max_kee",10000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",10000);
        set("sen",1000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",20);
        set_skill("blade",120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set_skill("godblade",120);
        set_skill("bss-steps",120);
        map_skill("dodge","bss-steps");
        map_skill("blade","godblade");
        setup();
        carry_object(CAP_OBJ"Hblade")->wield();
        carry_object(CAP_OBJ"Ns_boots")->wear();
        carry_object(CAP_OBJ"carmor")->wear();
        carry_object(CAP_OBJ"ironshield")->wear();
        carry_object(CAP_OBJ"ironarmband")->wear();

}
void init()
{
        add_action("do_fight","fight");
        add_action("do_fight","kill");
        if(this_player()->query("class")=="officer" && userp(this_player()))
        {
        call_out("check1",1);
        add_action("do_nod","nod");
        }
        else
        if(userp(this_player()))
        call_out("check2",1);
}


int do_fight(string arg)
{
        object who;
        who = this_player();

        if( !arg || (arg!="soldier" && arg!="castle soldier") )
                return notify_fail("你想攻击谁？\n");
        else {
                kill_ob(who);
tell_object(users(),HIR "皇门守卫大叫：有人硬闯皇城！皇上有令，杀无赦！！\n" NOR);
//                accept_kill(who);
        }

        return 1;
}
/*
int accept_kill(object who)
{
        int i;
        object ob, guard;
        ob = this_object();

        if( !present("king taigan", environment(ob)) ) {
        tell_room(environment(ob),HIW"\n突然！冲出两位守卫太监！\n\n"NOR);
     for(i=0;i<2;i++)
     {
        guard = new("/open/capital/room/sroom/npc/taigan1");
        guard->move(environment(ob));
        guard->kill_ob(who);
        }}
     tell_object(users(),HIR "守卫太监大叫：有人硬闯皇城！皇上有令，杀无赦！！\n" NOR);
        return 1;
}
*/
int check1()
{
        object me=this_player();
        int power;
        power=me->query("max_officer_power",1);
        if(power>=2000)
        {
                if(me->query_temp("can_in"))
                {
                command("say 大人里面请。\n");
                return 1;
                }
                command("say 大人要进京面圣吗?\n");
                return 1;
        }
        else
        {
                command("say 你的官阶太低，没办法进皇城。\n");
                return 1;
        }
}
int do_nod()
{
        object me=this_player();
        int power;
        power=me->query("max_officer_power",1);
        if(power>=2000)
        {
                me->set_temp("can_in",1);
                command("say 大人里面请。\n");
                return 1;
        }
        else
        {
                tell_object(me,"你觉得你点头点的要断了，可是都没用。\n");
                return 1;
        }
}
int check2()
{
        object me=this_player();
        command("say 皇城重地岂是你说进就进的地方，还不快滚!!!\n");
}
