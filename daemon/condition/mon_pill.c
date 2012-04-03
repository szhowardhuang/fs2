#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==0) 
     {  
     message_vision(HIW"$N身上长白山千年灵芝的神奇药效渐渐消失!!\n"NOR,me);
     return 0;
     }
     me->apply_condition("mon_pill",duration-1);
     message_vision(HIW"长白山千年灵芝的神奇药效迅速治疗$N的伤势!!\n"NOR,me);
     me->receive_curing("kee",1000);
     me->receive_heal("kee",1000);
     me->receive_curing("gin",1000);
     me->receive_heal("gin",1000);
     me->receive_curing("sen",1000);
     me->receive_heal("sen",1000);
     if( duration < 1 )
     return 0;
     return 1;
}

