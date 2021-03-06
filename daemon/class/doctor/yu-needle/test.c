// 医生的金针封穴
// design by chan
// (改版) by nike
// 将金针封穴改为打全体之招式...

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me,object target)
{
    object *enemy, ob, weapon;
    int i,value, sk_lv, em_lv, stab, attack, str;
    enemy=me->query_enemy();
    i=sizeof(enemy);

    if(!me->is_fighting(target))
	return notify_fail("金针封穴只能在战斗中使用。\n");
    if(!weapon=me->query_temp("weapon") || weapon->query("skill_type")!="stabber" )
	return notify_fail("要有适合的武器才能用金针封穴。\n");
    if( me->query("family/family_name") != "银针门" )
	return notify_fail("金针封穴只有银针门的门人才可以使用。\n");
    if((int)me->query_skill("yu-needle",1) < 40)
	return notify_fail("你的七奇针诀不够纯熟，无法使出金针封穴。\n");
    if((int)me->query("force")<300)
	return notify_fail("你的内力不够使出金针封穴。\n");
    if(target->is_busy() || enemy[i]->is_busy())
	return notify_fail("敌人现在不能动,快攻击吧!!!!\n");

	me->add("force",-300);
	value=query_function("gold-needle");
	sk_lv=me->query_skill("yu-needle",1);
	em_lv=target->query_skill("dodge"); //是算出enable dodge的值!!
	em_lv=em_lv /3;
	message_vision("
 "HIW"                $N暗运真气，手上的闪放出如"HIC"繁星"HIW"般的针芒，真气从针尖激射而出～\n\n"NOR""
""HIW"                            $N眼视$n全身大穴，繁星般点点使出～～\n\n"NOR""
""HIY"                                    "HIC+HBBLU"ψ "HIY"金 "HIW"-- "HIY"针 "HIW"-- "HIY"封 "HIW"-- "HIY"穴 "HIC"ψ\n\n"NOR""
""HIC"                        突然间～"HIY"漫天针芒"HIW"～向$n的全身大穴急袭而去！！！\n\n"NOR,me,target);
	stab = (int)me->query_skill("stabber",1);
	if(stab > 120) stab = 120;
	sk_lv=random(sk_lv);
	value=random(value);
	str = (int)me->query("str");

    if((value > 80) && (sk_lv > em_lv))
{
	message_vision(HIW"$n身上的奇经八脉被$N金针封住，身上的真气无法运行！\n" NOR,me,target);
	attack=stab*6;
	enemy[i]->receive_wound("kee",attack);
	str=str*2;
    if(100-str > 100)
	enemy[i]->start_busy(random(3)+2);
    else
	target->start_busy(3);
}
    else if((value > 60) && (sk_lv > em_lv))
{
	message_vision(HIY"$N一招使出，招式未待变老，旋即挺针直取$n的曲池穴！\n" NOR,me,target);
	attack=stab*6;
	enemy[i]->receive_wound("kee",attack);
	str=str*2.5;
    if(100-str > 100)
	enemy[i]->start_busy(random(3)+1);
    else
	target->start_busy(2);
}
    else if((value > 40) && (sk_lv > em_lv))
{
	message_vision(HIY"$n身上的气海穴被$N金针气劲所侵，真气运行为之一顿！\n" NOR,me,target);
	attack=stab*5;
	enemy[i]->receive_wound("kee",attack);
	str=str*3;
    if(100-str > 100)
	enemy[i]->start_busy(1);
    else
	target->start_busy(1);
}
    else if((value > 20 ) && (sk_lv > em_lv))
{
	message_vision(GRN"结果$n手太阴经脉诸穴被$N金针封住，功力大打折扣！\n" NOR,me,target);
	attack=stab*4;
	enemy[i]->start_busy(1);
	enemy[i]->receive_wound("kee",attack);
}
    else if((value > 0 ) && (sk_lv > em_lv))
{
	message_vision(GRN"$N翻身腾空，扶摇跃起，以迅雷不及掩耳之势刺向$n的关元穴！\n" NOR,me,target);
	target->start_busy(2);
}
	else
{
	message_vision(MAG"$n看出针芒中有一空隙，使出步法避开$N的攻击范围！\n" NOR,me,target);
}
	message_vision(HIR"$N使出金针封穴后，内劲损耗过大，赶紧运气调息！\n"NOR,me);
	me->start_busy(1);
	COMBAT_D->report_status(enemy[i],1);
	value = (int)query_function("gold-needle");
    if(value < 100)
	function_improved("gold-needle",random(me->query("max_force")/15+me->query_skill("yu-needle",1)/2));
	return 1;
}
