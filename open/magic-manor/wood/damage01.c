#include <ansi.h>
int up(object me);

void init()
{
	object me,ob,obj,mob,room;
	int kee1;
	me=this_player();

	if( me->query_temp("magic-manor/kill-wood01") >= 20 )
	{
	remove_call_out("up");
	call_out("up",1,me);
	}else{
	  if( !me->query("wood-monster") && !me->is_corpse() && me->is_character() && living(me) )
	  {
	  kee1=me->query("eff_kee");
	    if( random(200) > me->query_skill("dodge") )
	    {
	    message_vision(HIR"$N"HIR"һʱ���㲻������ͻ�������ٸ�������!!\n"NOR,me);
	    me->receive_wound("kee",kee1/50);
	    COMBAT_D->report_status(me,1); 
	    }else{
	    message_vision(HIW"$N"HIW"��ʱһ������������ٵĹ���!!\n"NOR,me);
	    }   
	  }

	  if( !present("wood monster",environment(me)) && !present("wood beast",environment(me)) )
	  {
	  mob = new(__DIR__"npc/wood-monster01");
	  mob->move(environment(me));
	  }
	}
	return ;
}

int up(object me)
{
	me=this_player();
	message_vision(HIG"��ɫ��������Χ������ȥ��һ�����ϵ�¥�ݽ���������$N��ǰ��\n"NOR,me);
	me->move("/open/magic-manor/wood/up01");
}