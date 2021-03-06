inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        object ob;
        set_name("小木妖", ({ "wood monster","wood","monster" }) );
        set("long","出没于木灵塔中的妖物，擅长使用藤蔓的召唤。\n");
        set("title",HIG"(绿色灵气)"NOR);
        set("age", 60);
        set("max_gin", 10000);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("max_force", 10000);
        set("force",10000);
        set("max_atman",10000);
        set("max_mana",10000);
        set("atman",10000);
        set("mana",10000);
        set("force_factor",10);
        set("attitude","aggressive");
        set("str", 35);
        set("cor", 35);
        set("spi", 35);
        set("int", 35);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/attack", 50);
        set("bellicosity",3000);
        set_skill("unarmed",100);
        set_skill("hell-evil",100);
        set_skill("mogi-steps",100);
        set_skill("move",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",100);
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
	map_skill("parry","hell-evil");
        map_skill("unarmed","hell-evil");

        set("combat_exp", 3000000);
        set_temp("def_fire",1);
	set("wood-monster",1);
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
	    if( !enemy[j] ) continue;
 	    {
 	    if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	    && living(enemy[j]) && !enemy[j]->query("wood-monster") ) 
	    mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if( random(10) > 6 && mob->is_fighting() )
	{
	message_vision(HIG"$N身上的绿色灵气和木灵塔相互感应，带刺的蔓藤随即袭向所有在场的人!!\n"NOR,mob);
          for (j=0 ; j < i ; j++)
          {
	    if( !enemy[j] ) continue;
 	    {
              if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
              && !enemy[j]->query("wood-monster") )
              {
		if( !enemy[j]->query_temp("magic-manor/gold-shield") )
		{
		message_vision(HIG"$N"HIG"已经避无可避，只能眼睁睁的让蔓藤在身上刺出无数血痕!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",400);
		COMBAT_D->report_status(enemy[j]);
		}else{
		message_vision(HIY"$N"HIY"身上的金灵之气缓和了部份的蔓藤的刺击!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",200);
		COMBAT_D->report_status(enemy[j]);
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
	if(me->query_temp("magic-manor/kill-wood02") <= 20)
	{
	me->add_temp("magic-manor/kill-wood02",1);
	}
	:: die();
}