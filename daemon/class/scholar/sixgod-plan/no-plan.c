#include <ansi.h>
// By Sueplan 策免计 - 儒门本身不怕计谋
//考滤要不要加call_out时间让plan的temp消掉
//这个计谋只能用来挡诸葛神算的plan, 不能挡sixgod-plan
inherit SSERVER;
object me=this_player();
int perform(object me,object target)
{
        if( me->query("sen") < 100 )
                return notify_fail("你的精神不够，无法使用。\n");
        if( target != me ) 
                return notify_fail("你要对谁用计 ?\n");
        if(me->is_fighting(target))     
                return notify_fail("策免计只能在战斗前使用。\n");
        if( me->query("force") < 2500 )
                return notify_fail("以你的内力不足以用此计。\n");
        if( me->query_temp("no-plan") == 1 )
        return notify_fail("你已经使出策免计了。\n");
message_vision(HIY"$N以六韬奇略中的策免计，使自己不怕别的计谋。\n"NOR,me);
        me->set_temp("speed",1);
        me->set_temp("empty",1);
        me->set_temp("mount",1);
        me->set_temp("false",1);
        me->set_temp("lock-link",1);
        me->set_temp("ghost",1);
        me->set_temp("rob",1);  
        me->set_temp("no-plan",1);
        me->add("force",-2000);
        return 1;
}
