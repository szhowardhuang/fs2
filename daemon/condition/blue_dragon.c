#include <ansi.h>
int i,j,k;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		int i = (int)me->query("combat_exp");

		tell_object(me,HIG"\n龙灭之魂，游走于你脑中，啃食着你的记忆与经验!!\n"NOR);

		if( me->query("/open/forest/clear_blue_dragon") )
		{
			me->delete("/open/forest/clear_blue_dragon");
			me->clear_condition("blue_dragon");
			k = (int)me->query("/open/forest/combat_exp");
			(int)me->set("combat_exp", k );
			me->delete("/open/forest/combat_exp");
			tell_object(me,HIC"藏于体内的封魄水晶，发现龙灭之魂，霎时将其困住!你回覆了所有记忆与经验!!\n\n"NOR);
		}
			
		else 
		{
			if( !me->query("/open/forest/combat_exp") )
			{
				tell_object(me,HIG"你眼神呆滞...顿时遗失一部份功力!!\n\n"NOR);
				(int)me->set("/open/forest/combat_exp", i );
				(int)me->add("combat_exp", -i/2);
			}
			else
			{
				j = (int)me->query("/open/forest/combat_exp");
				if ( i > j/10 )
				{
					tell_object(me,HIG"你的功力减退了不少...\n\n"NOR);
					(int)me->add("combat_exp", -j/20);
				}
				else
				{
					tell_object(me,HIW"你渐渐遗忘了一些招式...\n\n"NOR);
					(int)me->set("combat_exp",j/10);
				}
			}
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
