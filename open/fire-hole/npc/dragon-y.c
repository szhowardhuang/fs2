//修正心跳问题与限制exp上限bye cyw at 91/04/02
inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        object ob;
        set_name("黄光火龙", ({ "yellow dragon","dragon","yellow" }) );
        set("long",
                "全身泛着黄光的火龙, 首护着火龙窟的结界交点。\n");
        set("race", "野兽");
        set("title",HIY"(黄光)"NOR);
        set("age", 45000);
        set("attitude", "aggressive");
        set("family/family_name","火龙窟");
        set("max_gin", 180000);
        set("max_kee", 180000);
        set("max_sen", 180000);
        set("max_force", 2000000);
        set("force", 2000000);
        set("force_factor",20);
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
        set("combat_exp", 18000000);
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
        ob=carry_object("/open/fire-hole/obj/y-pill.c");
        ob->set_amount(3);
}
void heart_beat()
{
 object env,mob,target,obj;
 mixed enemy;
 int i,hurt,j=0;
 mob = this_object();
 env = environment(mob);
 enemy = all_inventory( environment(mob) );
 i=sizeof(enemy);
 mob->clear_condition();
 if( query("kee") < 0)
{mob->die();
 return ;
}
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
     && living(enemy[j]) && enemy[j]->query("id")!="yellow dragon" && userp(enemy[j]) && !wizardp(enemy[j]))    
 mob->kill_ob(enemy[j]);
 }//}
 if(random(10) > 4)
 {
    enemy = all_inventory( environment(mob) );
    i=sizeof(enemy);
    target=enemy[random(i)];
    if (mob->is_fighting())
    {
        message_vision( HIY
        "\n黄光火龙双眼一睁, 强烈的黄光由黄光火龙眼睛射出, 刺眼的光线遮蔽了你的视线!!\n"NOR,mob);
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){		
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && enemy[j]->query("id")!="yellow dragon"
            && environment(this_object())==environment(enemy[j]))
        {
        hurt = 800+random(700);
        if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
        hurt=hurt*2;
        if (enemy[j]->query("class")=="swordsman" || 
            enemy[j]->query("class")=="scholar" ||
            (enemy[j]->query_temp("def_fire")==1 
            && enemy[j]->query_temp("def_fire1")==1
            && enemy[j]->query("ring_type")>3))
        {enemy[j]->start_busy(1);}
        else
        {enemy[j]->start_busy(2);}
        enemy[j]->add("kee",-hurt);
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
        enemy[j]->set_temp("ko_y",1);   
        if(enemy[j]->query("combat_exp") < 18000000){ 
        tell_object(enemy[j],HIY"\n由于你的努力, 终于打倒了黄光火龙, 你辛苦的代价换来了宝贵的经验!!\n"NOR);
        tell_object(enemy[j],HIC"你的战斗经验上升 8000 点, 潜在能力上升 1500 点!!\n"NOR);
        enemy[j]->add("combat_exp",8000);
        enemy[j]->add("potential",1500); 
        }}}}
   ::die();

}
