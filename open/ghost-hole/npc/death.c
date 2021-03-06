inherit NPC;
#include <ansi.h>

mapping *action = ({
([     "action"     :   "$N冷冷的道："HIB"‘死到临头’"NOR"，纳命来吧！一声说完就向$n攻去！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    250,
                "force"      :    250,
                "damage_type":   "内伤",
           ]),
([     "action"     :   "$N一声唉叹：生命有何意，随即使出一招"HIB"‘一心求死’"NOR"，$n去死吧！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    350,
                "force"      :    350,
                "damage_type":   "暗伤",
           ]),
([     "action"     :   "$N疯狂的使出"HIB"‘嗜死如归’"NOR"，一股凶恶的神情令$n不敢逼视！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    300,
                "force"      :    450,
                "damage_type":   "内伤",
           ]),
([     "action"     :   "$N奸笑道：看我的"HIB"‘欲仙欲死’"NOR"，就让$n魂然忘我的死在$N手里吧！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    250,
                "force"      :    350,
                "damage_type":   "暗伤",
           ]),
([     "action"     :   "$N祭出一式"HIB"‘死神召唤’"NOR"，瞬间$n犹如死神降临一般，已无战力！",
                "dodge"      :   -35,
                "parry"      
                "damage"     :    350,
                "force"      :    250,
                "damage_type":   "无情撕伤",
           ]),
([     "action"     :   "$N怒声喝道：一式"HIB"‘虽死犹荣’"NOR"，死在$N手里，$n也不枉此生！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    500,
                "force"      :    500,
                "damage_type":   "撞伤",
           ]),
([     "action"     :   "$N身形摇摇欲坠，使出一式"HIB"‘哀莫大于心死’"NOR"，身形飘乎不定的攻向$n！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    450,
                "force"      :    350,
                "damage_type":   "裂伤",
           ]),
([    "action"     :    "$N暴发了全身的力量使出了"HIB"‘不死狂心’"NOR"，将所有力量聚集一点，向$n拼命袭去！",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    400,
                "damage_type":   "碎伤",
            ]), 
   });

void create()
{
        set("nickname",HIC"嗜死如命"NOR);
        set("title",HIB"【死】冥王"NOR);
        set_name("断魂绝", ({"ghost death","ghost","death"}));
        set("age",30);
        set("long","死灵骨魔的两大护法之一，负责掌管【死】，面如死灰，完全看不出一点表情，只有冷冷的一双间正注视着你。\n");
        set("gender","男性");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("attitude","aggressive");
        set("bellicosity",2000);
        set("max_gin",14000);
        set("gin",14000);
        set("max_sen",14000);
        set("sen",14000);
        set("max_kee",15000);
        set("kee",15000);
        set("combat_exp",10000000);
        set("max_force",90000);
        set("force",1000000);
        set("force_factor",40);
        set("clan_kill",1);
        set_skill("dodge",300);
        set_skill("force",200);
        set_skill("fireforce",150);
        set_skill("mogi-strike1",220);
        set_skill("mogi-steps",220);
        set_skill("unarmed",200);
        set_skill("parry",300);
        set_skill("literate",180);
        set_skill("move",200);
        map_skill("parry","mogi-strike1");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","fireforce");
  
        set_temp("apply/armor",800);
        set_temp("apply/damage",500);
        setup();
        add_money("cash",50);

        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();

}

mapping query_action()
{
        return action[random(sizeof(action))];
}
 
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,ghost;
 ob=this_object();
 ghost=present( "ghost",environment(ob) );
 if(str=="askgod ghost" || str=="askgod white-ghost"){
 write(HIY"死冥王冷笑：「别在我面前占卜了，准备料理你的后事吧！”\n"NOR);
 ghost->kill_ob(who);
 who->start_busy(1);
 return 1;                                                 
                  }
}

int accept_fight(object who)
{
return notify_fail("死冥王说道 : 死来吧！哈哈哈哈。\n");
}

int accept_kill(object who)
{
 who = this_player();
 kill_ob(who);
 return 1;
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j,force,count;
 mapping exit;
 string *exit_name;
 mob = this_object();
 env = environment(mob);
 count = random(100);
 
 if( count < 5 )
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"
$N一声狂喝"HIB"「魔音穿脑”"HIW"不断的向$n传来，你双耳鸣住
却也抵档不了这阵阵的魔音....
\n"NOR,mob);
      for(j=0;j < i;j++){
      message_vision(HIR"$N被这震人心神的魔音所伤，精神正不断的颓靡流失\n"NOR,(enemy[j]));
      enemy[j]->start_busy(2);
      enemy[j]->add("kee",-800);
      enemy->apply_condition("death",random(2)+1);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  

 if(count > 85 )
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"
$N起手一式"HIR"「焰火无界”"HIW"，一道道雄雄的烈火向$n飞扑而至
刹时间，$n已被雄雄的烈火所包围....
\n"NOR,mob,(enemy[j]));
      for(j=0;j < i;j++){
      message_vision(HIR"$N正被无情的烈火所烧着，发出阵阵痛苦的哀嚎声！！\n"NOR,(enemy[j]));
      enemy[j]->start_busy(2);
      enemy[j]->add("kee",-800);
      enemy->apply_condition("burn",random(5)+10);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  


   set_heart_beat(1);
   ::heart_beat();
   
}

