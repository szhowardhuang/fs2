// Chan 1/5重新修正
#include <ansi.h>

int update_condition(object me, int duration)
{
if(duration==0) return 0;
if( duration >= 1 )
  {
        tell_object( me , HIB "你的所受的内伤发作，只觉得胸口出现一阵阵绞痛。\n" NOR);
        message("vision", me->name() + "[32m忽然暗伤发作,脸上显示痛苦异常的表情.[0m \n",
        environment(me), me);
        me->add("kee",-150);
        me->add("eff_kee",-150);
        if( me->query("force") < 0 ) me->set("force",0);
        me->apply_condition("star-stial",duration -1);
        COMBAT_D->report_status(me, 1);
   }
  return 1;
}
