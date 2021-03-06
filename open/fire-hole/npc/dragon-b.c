//修正心跳问题与限制exp上限bye cyw at 91/04/02
inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        object ob;
        set_name("蓝光火龙", ({ "blue dragon","dragon","blue" }) );
        set("long",
                "全身泛着蓝光的火龙, 首护着火龙窟的结界交点。\n");
        set("race", "野兽");
        set("title",HIC"(蓝光)"NOR);
        set("age", 50000);
        set("attitude", "aggressive");
        set("family/family_name","火龙窟");
        set("max_gin", 140000);
        set("max_kee", 140000);
        set("max_sen", 140000);
        set("max_force", 2000000);
        set("force", 2000000);
        set("force_factor",40);
        set("str", 99);
        set("cor", 99);
        set("spi", 99);
        set("int", 99);
        set("bellicosity",10000);
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor",  200);
        set("combat_exp", 17000000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("unarmed",200);
        set_skill("force",500);
        set_temp("kang-power",1);
        set_temp("def_fire",1);
        set("no_plan_follow",1);
        set_temp("no_die_soon",1);
        set_temp("todie",3);
        setup();
        ob=carry_object("/open/fire-hole/obj/b-pill.c");
        ob->set_amount(3);

}
void heart_beat()
{
 object env,mob,target,obj;
 mixed enemy;
 int i,hurt,j=0,defire=0,ohurt;
 mob = this_object();
 env = environment(mob);
 enemy = all_inventory( environment(mob) );
 i=sizeof(enemy);
 mob->clear_condition();
 if( query("kee") < 0)
 {mob->die();}
 if(mob->query("kee") < mob->query("max_kee") && mob->query("force") < 1000000)
 {
    mob->receive_curing("kee",500);
    mob->receive_heal("kee",500);
    mob->add("force",10000);
 }
// if (!mob->is_fighting() || mob->is_fighting())
// {
 for (j=0 ; j < i ; j++)
 {
 if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
     && living(enemy[j]) && enemy[j]->query("id")!="blue dragon" && userp(enemy[j]) && !wizardp(enemy[j])) 
 mob->kill_ob(enemy[j]);
 }//}
 if(random(10) > 4)
 {
    enemy = all_inventory( environment(mob) );
    i=sizeof(enemy);
    target=enemy[random(i)];
    if (mob->is_fighting())
    {
        message_vision( HIR
        "\n蓝光火龙大吼一声, 火焰如排山倒海般的袭击而来!!\n"NOR,mob);
        mob->delete_busy();
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){	
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && enemy[j]->query("id")!="blue dragon"
            && environment(this_object())==environment(enemy[j]))
        {
        hurt = 2000+random(1500);
        if(!enemy[j]->query("ring_type"))
        defire=500;
        else if(enemy[j]->query("ring_type")==1)
        defire=600;
        else if(enemy[j]->query("ring_type")==2)
        defire=700;
        else if(enemy[j]->query("ring_type")==3)
        defire=800;
        else if(enemy[j]->query("ring_type")==4)
        defire=900;
        else if(enemy[j]->query("ring_type")==5)
        defire=1000;
        if (enemy[j]->query("family/family_name")=="雪苍派" && enemy[j]->query_temp("keeup")==1)
        {hurt = 2500+random(2500);
         enemy[j]->apply_condition("hart",100);
         enemy[j]->set("force_factor",0);
         tell_object(enemy[j],HIY"由于你的雪苍内劲被火焰打散, 使你无法施力并受到数倍的伤害!!\n"NOR);}
        ohurt=hurt;
        if (enemy[j]->query_temp("def_fire")==1        //增加火龙鳞与焰气诀加乘效果
        && enemy[j]->query_temp("def_fire1")==1)           
        {hurt = hurt - defire - 700;
        tell_object (enemy[j],HIG"你身上的焰气诀与火龙鳞发生共鸣缓和了蓝光火龙的火焰!!\n"NOR);}
        else if (enemy[j]->query_temp("def_fire")==1)                                    
        {hurt = hurt - 1000;
        tell_object (enemy[j],HIG"你身上的焰气诀缓和了蓝光火龙的火焰!!\n"NOR);}
        else if (enemy[j]->query_temp("def_fire1")==1)
        {hurt = hurt - defire*1.2;
        tell_object (enemy[j],HIG"你身上的火龙鳞缓和了蓝光火龙的火焰!!\n"NOR);}
        else if (enemy[j]->query_temp("gold-fire")==1 &&   //增加极火金身也可以挡掉500点功击
        enemy[j]->query("functions/gold-fire/level","gold-fire") == 90)
        {hurt = hurt -500;
        tell_object (enemy[j],HIG"你身上的极火金身缓和了蓝光火龙的火焰!!\n"NOR);}   
 //       message_vision( HIG
 //       "\n火龙鳞耐火值为"+defire+",火龙原始害值为"+ohurt+",最后伤害值为"+hurt+"!!\n"NOR,mob);        
        enemy[j]->add("kee",-hurt);
        enemy[j]->start_busy(1);
        enemy[j]->apply_condition("burn",30);
        COMBAT_D->report_status(enemy[j]);
        }}}
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
void die()
{
   int i,j=0;
   object *enemy,mob,me;
   me = this_player();
   mob = this_object();
   enemy = mob->query_enemy();
   i=sizeof(enemy);
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){
        if(environment(this_object())==environment(enemy[j]) && userp(enemy[j])){
        enemy[j]->set_temp("ko_b",1);  
        if(enemy[j]->query("combat_exp") < 17000000){  
        tell_object(enemy[j],HIY"\n由于你的努力, 终于打倒了蓝光火龙, 你辛苦的代价换来了宝贵的经验!!\n"NOR);
        tell_object(enemy[j],HIC"你的战斗经验上升 7500 点, 潜在能力上升 1500 点!!\n"NOR);
        enemy[j]->add("combat_exp",7500);
        enemy[j]->add("potential",1500);
        }}}}
   ::die();

}
