// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
        
        set_name("青衣魔将",({"seven-dark"}));
        set("long",
   "\n恼森青衣, 身形如云过青空, 是七人之中身手最健者.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人类");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",13000);
        set("max_kee",13000);
        set("max_sen",13000);
        set("max_force",15000);
        set("force",15000);
        set("force_factor",95);
        set("combat_exp",6900000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",200);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike1",100);
        set_skill("force",120);
        set_skill("badforce",90);
        set("clan_kill",1);
        map_skill("unarmed", "mogi-strike1");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike1");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"头部","胸部","背部","腰部"}));
        setup();
carry_object(C_OBJ"/ninepill");
        carry_object("open/mogi/castle/obj/seven6-dark-head");

        add_money("gold",5);
 }


void heart_beat()
{
 object env,mob,*enemy,target;
 int i;

 mob = this_object(); 
 env = environment(mob);  

 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 15)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=offensive_target(mob);
    if(!target) return ;
    if( env == environment(target) )
    {
      message_vision(HIY"\n
$N气应魔元，狂风骤作，整个奈何之路均被笼罩其中，光渐渐地被 
黑闇吞没了
暗雷轰动，一式"HIM"‘魔龙卷云  夜漠移换’"HIY"乍然发动了，魔气在空中
狂奔蚀向所有人
\n"NOR,mob,target);
      target->receive_damage("kee",650);
      target->start_busy(2);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}
