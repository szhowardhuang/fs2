#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIR"$NËÄÖÜµÄÁÒÑæºÆÆøÂýÂýÍËÉ¢!!\n"NOR,me);
     me->delete_temp("kang-power");
     return 0;
     }
     me->apply_condition("kang_pill",duration-1);
     if( duration < 1 )
     return 0;
     return 1;
}
