//by roger

inherit NPC;
#include <ansi.h>
void create()
{
        set("nickname","天邪峰三妖狐");
        set_name("银妖狐", ({"silver-ghost","ghost"}));
        set("age",900);
        set("long","天邪峰妖三妖狐之一，负责保护催动妖狐阵的金妖狐。\n");
        set("gender","女姓");
        set("str",30);
        set("con",30);
        set("cor",30);
        set("cps",30);
        set("bellicosity",500);
        set("attitude","aggressive");
        set("max_gin",1100);
        set("gin",1100);
        set("max_sen",1100);
        set("sen",1100);
        set("max_kee",2000);
        set("kee",2000);
        set("combat_exp",1550000);
        set("max_force",3300);
        set("force",3300);
        set("force_factor",10);
        set_skill("dodge",80);
        set_skill("force",100);
        set_skill("badforce",100);
        set_skill("nine-steps",85);
        set_skill("unarmed",90);
        set_skill("hell-evil",90);
        set_skill("parry",100);
        set_skill("move",50);
        map_skill("unarmed","hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("move","nine-steps");
        map_skill("force","badforce");
        map_skill("parry","hell-evil");
  
        set_temp("apply/armor",80);
        set_temp("apply/damage",30);
        setup();
        add_money("gold",20);
        
}                     

void heart_beat()
{
 object env,mob,*enemy,target,ghost;
 int i,kee;
 //string gold-ghost;
 
 mob = this_object();
 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 11 && present("gold-ghost",environment(mob)))
 {
    
message_vision(HIW"\n银妖狐护卫在金妖狐的身旁念起回复妖咒，治好了金妖身上的伤\n"NOR,this_object());
  ghost = present("gold-ghost",environment(mob));
    if(ghost){
  kee=(ghost->query("eff_kee") - ghost->query("kee"));
  ghost->add("kee",kee/10);
    }
  
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}
