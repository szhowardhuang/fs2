#include <ansi.h>
#include <combat.h>

inherit NPC;

int special_att();

void create()
{
        seteuid(getuid());
        ::create();
        set_name("天地云龙", ({ "npc06", "dragon" }) );
        set("long", "它是由云雾幻化而成神龙，专杀妖魔鬼怪。\n");

        set("race","野兽");
        set("gender","雄性");
        set("attitude", "friendly");
        set("max_gin", 4000);
        set("max_sen", 4000);
        set("max_kee", 4000);
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("max_force", 6000);
        set("force", 6000);
        set("force_factor",15);
        set("str", 30);
        set("cor", 30);
        set("cps", 25);
        set("limbs",({"头部","胸部","腹部","前爪","后爪","尾巴"}));
        set("verbs",({"bite","claw"}));

        set ("chat_chance_combat",30);
        set ("chat_msg_combat", ({(: special_att :)}));

        setup();

}

void callset(object who)
{
        int pp;
        object me = this_object();
        
        pp=who->query("combat_exp");
     
        set("combat_exp",pp*3+1000);
        set_temp("apply/defend",pp/50);
        set_temp("apply/attack",pp/50);
        set("max_kee",pp/600);
        set("kee",pp/600);
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIB"凶暴的$N渐渐平息下来，再度变为云雾。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}

int special_att()
{
        object me = this_object(), victim, *enemy = query_enemy();
        int i;

        if( !i = sizeof(enemy) )
                return 0;

        victim = enemy[random(i)];
        message_vision (HIB"$N一声怒吼，一道闪电向$n直劈而来。\n"NOR,me,victim);
        victim->receive_damage("kee",100);      
        COMBAT_D->report_status(victim);       
  
        return 1;
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
if(me->query("quest/start_game")< 7)
       {
        tell_object(users(),HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第六层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第七层试炼□塔"HIG"’"HIW"。
	"NOR);
	me->set("quest/start_game",7);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}