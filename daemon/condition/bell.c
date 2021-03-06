#include <ansi.h>

int update_condition(object me, int duration)
{
        if(duration==0)
        {
                me->add_temp("apply/damage",-1*me->query_temp("bellup_buf"));
                me->add_temp("apply/attack",-1*me->query_temp("bellup_buf"));
                me->add_temp("apply/dodge",-1*me->query_temp("bellup_buf"));
                me->delete("bellup");
                message_vision(
                HIC "$N身上的杀气消失了，脸色也变得比较温和。\n" NOR,me);
                return 0;
        }
        me->apply_condition("bell",duration-1);
        message_vision(
        HIR "$N杀气腾腾，激起四周的气流，产生一股狂风。\n" NOR,me);
        if( duration < 1 ) return 0;
        return 1;
}
