inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        object ob;
        set_name("ˮ����", ({ "water beast","water","beast" }) );
        set("long","��û�ڽ������е�����ó�ʹ��ǿ�қ�����\n");
        set("title",HIC"(ˮɫ����)"NOR);
        set("age", 60);
        set("max_gin", 30000);
        set("max_kee", 30000);
        set("max_sen", 30000);
        set("max_force", 15000);
        set("force",15000);
        set("max_atman",30000);
        set("max_mana",30000);
        set("atman",30000);
        set("mana",30000);
        set("force_factor",15);
        set("attitude","aggressive");
        set("str", 35);
        set("cor", 35);
        set("spi", 35);
        set("int", 35);
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 80);
        set_temp("apply/attack", 80);
        set("bellicosity",10000);
        set_skill("unarmed",150);
        set_skill("hell-evil",150);
        set_skill("mogi-steps",150);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
	map_skill("parry","hell-evil");
        map_skill("unarmed","hell-evil");

        set("combat_exp", 5000000);
	set("water-monster",1);
        setup();
}

void heart_beat()
{
	object mob,me,obj;
	mixed enemy;
	int i,j=0;
	mob = this_object();
	me = this_player();
	enemy = all_inventory( environment(mob) );
	i=sizeof(enemy);

	if( !mob->is_fighting() || mob->is_fighting() )
	{
	  for (j=0 ; j < i ; j++)
	  {
	    if(!enemy[j]) continue;
 	    {
 	    if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	    && living(enemy[j]) && !enemy[j]->query("water-monster") ) 
	    mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if( mob->is_fighting() )
	{
	  if( random(10) < 6 )
	  {
	  message_vision(HIC"$N���ϵ�ˮɫ������ˮ�����໥��Ӧ������������Ѹ��������Ϯȥ!!\n"NOR,mob);
            for( j=0 ; j < i ; j++ )
            {
	      if( !enemy[j]) continue;
	      {
		if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
		&& !enemy[j]->query("water-monster") )
		{
		  if( !enemy[j]->query_temp("magic-manor/soil-shield") )
		  {
		  message_vision(HIC"$N"HIC"ֻ��ȫ��������ľ����ʹ������������������Ĺ�����!!\n"NOR,(enemy[j]));
		  enemy[j]->receive_wound("kee",450);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision(YEL"$N"YEL"���ϵ�����֮�������˲��ݵĶ�������ʹ��$N"YEL"�ܴ���Ϊ��С!!\n"NOR,(enemy[j]));
		  enemy[j]->receive_wound("kee",220);
		  COMBAT_D->report_status(enemy[j]);
		  }
                }
	      }
	    }
	  }
	}   
	set_heart_beat(1);
	::heart_beat();
}

void die()
{
	object me=query_temp("last_damage_from");
	if(me->query_temp("magic-manor/kill-water04") <= 20)
	{
	me->add_temp("magic-manor/kill-water04",1);
	}
	:: die();
}