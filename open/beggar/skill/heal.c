
#include <ansi.h>

int exert(object me, object target)
{

        if( target!=me ) {
                tell_object(me, "你只能帮自己疗伤。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                tell_object(me, "战斗中运功疗伤？找死吗？\n");
                return 1;
        }
        if( (int)me->query("force") < 50 ) {
                tell_object(me, "你的内力不足，无法使用洗髓经来疗伤。\n");
                return 1;
        }

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 3 )
                return notify_fail("你已经受伤过重，只怕一运真气会被洗髓劲反扑！\n");

        write( HIW "你盘坐在地，逆运洗髓经调理你全身的伤势，使你的伤势好多了。\n" NOR);
        message("vision",
                me->name() + "运起洗髓经开始疗伤，一股真气从头上冒出，吐出一口瘀血，看起来好多了。\n",
                environment(me), me);

        me->receive_curing("kee", ( 10 + (int)me->query_skill("force")/10 + (int)me->query_skill("dragonforce")/10 ) * 3);
        me->add("force", -( 50 ) );
        if( me->query("force")<0 )
                me->set("force", 0);

        return 1;
}
