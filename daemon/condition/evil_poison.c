#include <ansi.h>


int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		message_vision(HIY"\n$N呕吐过后～脸色渐渐的回复了红润。\n\n"NOR,me);
                tell_object(me,HIW"你感觉舒服多了。\n"NOR);
                return 0;
        }

	if( duration >= 10 )
	{
		message_vision(RED"\n$N蛊毒发作～全身狂抖不停～\n\n"NOR,me);
		me->receive_wound("gin",(int)me->query("max_gin")/50);
		me->receive_wound("kee",(int)me->query("max_kee")/50);
		me->receive_wound("sen",(int)me->query("max_sen")/50);
		COMBAT_D->report_status(me, 1);
		me->apply_condition("evil_poison", duration-1 );
  		return 1;
	}	
	if( duration >= 1 )
	{
		message_vision(YEL"\n$N不断的呕吐～吐出了许多的蛊虫～\n\n"NOR,me);
		me->receive_wound("gin",(int)me->query("max_gin")/100);
		me->receive_wound("kee",(int)me->query("max_kee")/100);
		me->receive_wound("sen",(int)me->query("max_sen")/100);
		COMBAT_D->report_status(me, 1);
		me->apply_condition("evil_poison", duration-1 );
  		return 1;
	}
        if( duration < 1 ) 
        return 0;
return 1;
}
