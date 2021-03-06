inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("莫无乐", ({ "run mou", "run", "mou" }));
        set("title",HIW"～幻影～"NOR"魔龙魔刀");
        set("nickname", "尸死无涯");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "aggressive");
        set("long","莫无乐是莫无愁的同门，但想篡夺门主之位，而与独孤嵊合作。\n");
        set("str", 45);
        set("cps", 45);
        set("cor", 45);
        set("have_book",1);
        set("mpower",1);
        set("env/魔性六斩","YES");
        set("bellicosity",3000);
        set("combat_exp",12000000);
        set("max_force", 500000);
        set("force", 500000);
        set("max_kee",50000);
        set("max_gin",10000);
        set("max_sen",10000);
        set("force_factor", 30);
        set_skill("force", 120);
        set_skill("parry",120);
        set_skill("dodge",120);
        set("functions/mdragon-dest/level",100);
        set_skill("blade",120);
        set_skill("dragon-blade",120);
        set_skill("powerforce",120);
        map_skill("force", "powerforce");
        map_skill("blade", "dragon-blade");
        map_skill("parry", "dragon-blade");
        set("chat_chance_combat",90);
        set("chat_msg_combat",({
            (: perform_action, "blade.mdragon-dest"   :)
        }));
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        setup();
        carry_object("/daemon/class/blademan/obj/mar-blade")->wield();
        carry_object("/open/gblade/obj/dragon_book");
        add_money("gold",10);
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i;
 mob = this_object();
 env = environment(mob);
if( random(100) > 40)
 {
    enemy=mob->query_enemy();
    if(i=sizeof(enemy)) {
target=enemy[random(i)];
    if( env == environment(target) )
    {
message_vision(HIW"\n                        ～幻～影～心～诀～

"HIC"
莫无乐表情狰狞，施展出魔龙魔刀‘屠人千万～血流遍野’\n"+
"$N闪避不及，被打中要害，血流满地\n"NOR,target);
	mob->add("kee",3000);
      target->receive_damage("kee",1400,mob);
      COMBAT_D->report_status(target,1);
    }
 }
}
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
if(me->query("quest/start_game")< 33)
       {
        tell_object(me,HIY"
恭喜"HIW+me->query("name")+HIY"挑战"HIG"‘"HIR"第三十二层试炼□塔"HIG"’"HIY"通过！！

"HIW"希望"+me->query("name")+"能不负众望，勇闯"HIG"‘"HIY"第三十三层试炼□塔"HIG"’"HIW"。
	"NOR);
	me->set("quest/start_game",33);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系统：你已经通过测试，系统不做任何更改。\n"NOR);
	destruct(this_object());
}
}
