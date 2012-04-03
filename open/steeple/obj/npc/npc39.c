#include <ansi.h>
inherit NPC;
void create() {
        
        set_name("墨衣魔将",({"seven-dark"}));
        set("long",
   "\n黟夜黔衣, 擅使毒, 见闻世间百毒千草, 医术亦更上一层.\n");

        set("age",3121);
       set("title",HIW"～幻影～"NOR);
        set("str",35);
        set("cor",35);
        set("race","人类");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",7500);
        set("max_gin",13300);
        set("max_kee",50000);
        set("max_sen",13300);
        set("max_force",500000);
        set("force",500000);
        set("force_factor",50);
        set("combat_exp",13000000);
        set_skill("unarmed",100);
        set_skill("dodge",90);
        set_skill("mogi-steps",80);
        set_skill("move",80);
        set_skill("parry",80);
        set_skill("literate",170);
        set_skill("mogi-strike5",100);
        set("clan_kill",1);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("unarmed", "mogi-strike5");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike5");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"头部","胸部","背部","腰部","毒掌"}));
        setup();
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
 
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"\n                        ～幻～影～心～诀～

"HIM"\n
一瞬间，魔气暴涨，回风如割，压风如打，毒气从地面上渗出，透进魔风之中
$N一声低喊"HIW"‘送葬行列  剖天坟地’"HIM"，顿时气旋炸裂，$n无所遁逃
\n"NOR,mob,target);
      target->add("force",-1800);
      target->receive_wound("kee",1800);
	mob->add("kee",1800);
      COMBAT_D->report_status(target, 1);

    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系统：战斗停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系统：由于你没携带晶片，所以无法记录战绩。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系统：由于你没有正式登记，资料无法传输。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 40)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第三十九层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第四十层试炼□塔"HIG"’"HIW"。
	"NOR,me);
	me->set("quest/start_game",40);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}
