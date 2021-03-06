//by roger
inherit NPC;
#include <ansi.h>
#include "castle.h"
void create()
{
        set("nickname",HIW"黑白双刹"NOR);
        set_name("白刹艳女", ({"white-ghost","ghost"}));
        set("age",8710);
        set("long","焚天魔王的两大护法之一，长得极其美艳的女妖，练有阴毒邪功「发天杀”和「乱雪冰天”\n");
        set("gender","女姓");
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
        set("combat_exp",7200000);
        set("max_force",9000);
        set("force",19000);
        set("force_factor",40);
        set("clan_kill",1);
        set_skill("dodge",100);
        set_skill("force",100);
        set_skill("badforce",100);
        set_skill("mogi-steps",120);
        set_skill("unarmed",100);
        set_skill("mogi-strike3",120);
        set_skill("parry",100);
        set_skill("literate",180);
        set_skill("move",100);
        map_skill("unarmed","mogi-strike3");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        map_skill("parry","mogi-strike3");
  
        set_temp("apply/armor",70);
        set_temp("apply/damage",70);
        setup();
        carry_object("open/mogi/castle/obj/white-ghost-head");
        carry_object(C_OBJ"/ninepill");
        carry_object(C_OBJ"/ninepill");
        add_money("gold",25);
        
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
 write(HIY"白刹艳女冷笑：「在魔王的地盘上面前求神问卜!?先问问魔王还差不多。”去死吧!!\n"NOR);
 ghost->kill_ob(who);
 return 1;                                                 
                  }
}

int accept_fight(object who)
{
return notify_fail("白刹艳女说道 : 我没空陪你玩。\n");
}
int accept_kill(object me)
{
    object ob,ghost;
    ob=this_object();
    ghost=present( "ghost 2",environment(ob) );
     if( !present( "ghost 2",environment(ob))||!living(ghost)) return 1;
    else {
    message_vision(HIY"\n黑刹郎君看到白刹艳女有难，马上向$N下了辣手攻击！\n"NOR,me);
     ghost->kill_ob(me);
    return 1;
   }
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j,force;
 mapping exit;
 string *exit_name;
 
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
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"
瞬间, 冷雪纷纷, 阴风惨惨, 白霜如星落, 银萃如光转, 仿佛冻结
了血液一般, 凝止了一切
只见$N左手轻轻一拂, 漫天冰雪疾飞狂转, 一式"HIB"「乱雪冰天”"HIW"
朝着所有有温度之物袭去
\n"NOR,mob);
      for(j=0;j < i;j++){
      enemy[j]->start_busy(1);
      enemy[j]->add("kee",-700);
      enemy->apply_condition("cold",20);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }
	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj1/light_emblem")->move(environment(winner));
	  message_vision(HIM"\n从白刹艳女的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/light_emblem",sprintf("%s(%s) 让白刹艳女掉下了光之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj1/light_emblem")->move(environment(winner));
	  message_vision(HIM"\n从白刹艳女的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/light_emblem",sprintf("%s(%s) 让白刹艳女掉下了光之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}