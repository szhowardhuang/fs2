//copy from cage,re-edit from ccat

#include <ansi.h>
inherit NPC;

mapping *action = ({
([ "action" : "$N手成爪状,对准$n"+HIW+"脑门"NOR+"直插而下,正是九阴白骨爪第一招"+
               HIW+" 破首式"NOR,
                "dodge"      :    -25,
                "parry"      :    -25,
                "damage"     :    200,
                "damage_type":   "抓伤",
           ]),
([ "action" : "$N双爪交错而过,对准$n"+HIW+"胸口"NOR+"抓去,正是九阴白骨抓之第二招"+
               HIW+" 开膛式"NOR,
                "dodge"      :      -5,
                "parry"      :     -15,
                "damage"     :     180,
                "damage_type":   "抓伤",
           ]),
([ "action" : "$N双爪穿过$n的防御圈,由下而上往$n之"+HIW+"喉咙"NOR+"抓去,正是九阴白骨爪之"+
              "第三招"+HIW" 断喉式"NOR,
                "dodge"      :     30,
                "parry"      :     30,
                "damage"     :    100,
                "damage_type":   "抓伤",
            ]),
([ "action" : "$N一爪在前,一爪在后,迅急无比的往$n"+HIW+"心脏"NOR+"挖去,正是九阴白骨爪之"
             +"第四招"+HIW" 腕心式"NOR,
                "dodge"      :     5,
                "parry"      :     5,
                "damage"     :   200,
                "damage_type":   "抓伤",
            ]),                
   });

void create()
{
        set("title","黑风双刹");
        set_name("梅超风", ({"mechoufen"}));
        set("age",35);
        set("long","曾经名动江湖一时,手中杀人无数,黑风双刹之铜尸,梅超风.\n");
        set("gender","女姓");
        set("str",30);
        set("con",30);
        set("max_kee",20000);
        set("kee",20000);
        set("combat_exp",350000);
        set("max_force",10500);
        set("force",10500);
        set("force_factor",25);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("linpo-steps",80);
        set_skill("unarmed",80);
        map_skill("dodge","linpo-steps");
        set("chat_chance_combat",25);
        set("chat_msg_combat",({
        "梅超风说: 你是哪来的高手,竟赶来打扰我修练!!\n",
        "梅超风说: 不教训你,你不知道我黑风双刹的可怕!!\n",
        "梅超风说: 杀杀杀杀!!!\n",
        }));
        set_temp("apply/armor",100);
        set_temp("apply/damage",80);
        setup();
       carry_object("/open/gsword/obj/sick_item");
        carry_object("open/center/obj/mechoufen-head");
        add_money("gold",25);
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        
        reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void greeting(object ob)
{
    int exp,lv_1;
    string skill;
    object weapon;
    exp =ob->query("combat_exp",1);
    if( exp < 100000 )
    {
      say("梅超风说: 喂!!"+ob->name(1)+"!! 这里不是肉脚该来的地方,快滚吧!!\n");
      return;
    }else{
      weapon = ob->query_temp("weapon");     
      if( weapon ) skill = weapon->query("skill_type");
      else skill = "unarmed";
      lv_1 =(int) 1.8 * ob->query_skill(skill, 1);
      if( lv_1 > 50)
      {
        set_skill("unarmed", lv_1);
        set_skill("force", lv_1);
      }
      exp = exp * 1.5;
      set("combat_exp",exp);
      kill_ob(ob);
      ob->kill_ob(this_object());
    }
    return;
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);
 
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    kee = target->query("max_kee") * 0.4;
    if( env == environment(target) )
    {
      message_vision(HIR+"$N一个不留意,被九阴白骨爪正面击中!!!\n"+NOR,target);
      target->receive_damage("kee",(int)kee,mob);
      COMBAT_D->report_status(target,0);
    }
 }
 
 if((mob->query("kee")<mob->query("max_kee")*0.5) && (random(100) < 20) )
 {
    tell_room(environment(), HIY+name()+"运起九阴真经之气疗法,为自己"
               +"疗伤.\n"+NOR);
    mob->receive_curing("kee",700);
    mob->receive_heal("kee",700);
 }

 if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 20) )
 {
   exit = env->query("exits");
   exit_name = keys(exit);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
 }
   
   set_heart_beat(1);
   ::heart_beat();
   
}
