inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("火蜥蜴", ({ "fire lizard","fire","lizard" }) );
        set("long",
                "这是一只栖息在火龙窟的蜥蜴，体积庞大但是动作极为灵活。\n");

        set("race", "野兽");
        set("age", 110);
        set("attitude", "friendly");
        set("max_gin", 40000);
        set("max_kee", 75000);
        set("max_sen", 40000);
        set("str", 80);
        set("cor", 50);
        set("spi", 70);
        set("int", 40);
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",10000);
        set("max_force",30000);
        set("force",50000);
        set_temp("apply/armor", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/attack", 180);
        set("force_factor",20);
        set("combat_exp", 9500000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_temp("kang-power",1);
        setup();
        carry_object("/open/common/obj/liz_meat.c");
}

void heart_beat()
{
	object me,mob,*enemy;
	int bu,i,j;
	me=this_player();
	mob=this_object();
	bu=(int)mob->query_busy();
	enemy=mob->query_enemy();
	i=sizeof(enemy);

	if( bu <= 0 ) bu=1;
	if( bu > 10 ) bu=9;

	if( mob->is_fighting() && mob->is_busy() && random(100) > 50 )
	{
	  switch(random(100))
	  {
	  case 0..30:
      message_vision(HIR"火蜥蜴的背部硬皮上泛起一片红光，红光衍生了炽热赤焰火网!!\n"NOR,me);
		for( j=0 ; j<i ; j++ )
	    {
	      if( !enemy[j] ) continue;
	      {
			if( random(10) > 2 )
	        {
		    message_vision(HIR"赤焰火网直奔$N"HIR"而去，$N"HIR"一时无法反应被火网困住了!!\n"NOR,enemy[j]);
		    enemy[j]->start_busy(1);
	        COMBAT_D->report_status(enemy[j]);
			}else{
	        message_vision(HIW"$N轻轻向后翻落，已落在火网三丈之外，火网只能无功而返。\n"NOR,enemy[j]);
	        COMBAT_D->report_status(enemy[j]);
			}
		  }
	    }
	  break;

	  case 31..100:
	  message_vision(HIR"火蜥蜴狂啸一声，发出强大的反震力，想要挣开身上所受的束搏!!\n"NOR,me);
		for( j=0 ; j<i ; j++ )
	    {
	      if( !enemy[j] ) continue;
	      {
			if( random(35000) > enemy[j]->query("max_force")  )
	        {
		    message_vision(HIR"$N"HIR"一个躲避不及，给震的气血翻腾，一时间气血难以调适!!\n"NOR,enemy[j]);
		    enemy[j]->receive_wound("kee",bu*150);
		    enemy[j]->receive_wound("gin",150);
		    enemy[j]->receive_wound("sen",150);
	        COMBAT_D->report_status(enemy[j]);
			}else{
	        message_vision(HIW"$N仗着深厚的内功，将这道震力给完全卸了开去。\n"NOR,enemy[j]);
	        COMBAT_D->report_status(enemy[j]);
			}
		  }
	    }
	  break;
	  }
	}

	if( mob->query("kee") <= 0 )
	{
	mob->die();
	}
    set_heart_beat(1);
	::heart_beat();
}