#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
skill=this_player()->query("functions/blood/level");
        if(userp(me))
        return notify_fail("请改用 mixforce。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("血穹苍必须使用浑天心法才能发挥威力。\n");
        if( target != me ) return notify_fail("你只能用浑天心法提升内力威力。\n");
        if (me->query_skill("superforce",1) < 200)
            return notify_fail("你的浑天心法等级不足，须要 200 级。\n");
        if (me->query("force") < 550+skill*5)
            return notify_fail("你的内力不够，无法使用血穹苍。\n");
        if( (int)me->query("max_force") < 2000 )
        return notify_fail("你的内力根基不足,无法控制血穹苍气劲。\n");
        if(me->query_temp("blood")) return notify_fail("你已经在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已经在运行[32m紫星河心法[0m了。\n");
        if(me->query_temp("white")) return notify_fail("你已经在运行[37m白云烟心法[0m了。\n");
        if(me->query_temp("nine")) return notify_fail("你已经在运行[35m玖荡霞心法[0m了。\n");
        if(me->query_temp("gen")) return notify_fail("你已经在使用[35m土昆仑心法[0m了。\n");
        if(me->query_temp("ice")) return notify_fail("你已经在运转[37m碧雪冰心法[0m了。\n");
        if(me->query_temp("black")) return notify_fail("你已经在运行[30m玄混沌[0m了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已经在催运[34m靛沧海[0m内劲了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已经在强运[33m金晨曦[0m内劲了。\n");
        if(me->query_temp("green")) return notify_fail("你已经在运行[32m玄宇宙[0m内劲了。\n");

        me->set_temp("blood",1);
        message_vision(
        HIC "$N运起浑天心法第九层"HIR"[血穹苍]"HIC"，将真气运布全身，刹时全身冒出血红色的蒸气!!\n" NOR,me);
        me->add_temp("apply/force", 70);
        me->add_temp("apply/parry", 60);
        me->add_temp("apply/unarmed", 80);
        me->add_temp("apply/stick", 60);
        me->add_temp("apply/move", -50);
        me->add_temp("apply/dodge", -40);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return ;
        me->set_temp("blood",0);
        me->add_temp("apply/force", -70);
        me->add_temp("apply/parry", -60);
        me->add_temp("apply/unarmed", -80);
        me->add_temp("apply/stick", -60);
        me->add_temp("apply/move", 50);
        me->add_temp("apply/dodge", 40);
        tell_object(me,"只见你身上的[31m血穹苍[0m气劲回归平淡。\n");
        if(skill < 200)
        function_improved("blood",random(1000));
}
