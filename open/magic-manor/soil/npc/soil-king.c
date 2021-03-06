inherit NPC;
#include "/open/open.h"
#include <ansi.h>

void create()
{
	set_name("土爆波", ({ "soil king","soil","king" }) );
	set("long","土灵塔的镇塔之王，能力比小土妖和土灵兽不知强上几倍。\n");
	set("title",YEL"(土色灵气)"NOR"土灵塔王"NOR);
	set("gender","男性");
	set("class","bandit");
    set("family/family_name","恶人谷");
	set("age", 60);
	set("str", 35);
	set("cor", 35);
	set("spi", 35);
	set("int", 35);

	set("combat_exp",8000000);
	set("bellicosity",3000);
	set("max_gin", 50000);
	set("max_kee", 50000);
	set("max_sen", 50000);
	set("max_force", 20000);
	set("force",20000);
	set("max_atman",50000);
	set("max_mana",50000);
	set("atman",50000);
	set("mana",50000);
	set("force_factor",20);
	set("attitude","aggressive");

	set_skill("dodge",120);
	set_skill("sword",120);
	set_skill("ghost-steps",120);
	set_skill("force", 120);
	set_skill("badforce",120);
	set_skill("move", 120);
	set_skill("parry",120);
	set_skill("unarmed",120);
	set_skill("badstrike",120);

	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");

	set("functions/evil-blade/level",100);
	set("functions/badroar/level",100);

	set("chat_chance_combat", 45);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	(: perform_action, "unarmed.badroar" :),
	}) );

	set("quests/badroar",1);
	set("marks/kar",1);
	set("soil-monster",1);

	set_temp("apply/armor", 150);
	set_temp("apply/defense", 250);

	setup();

	add_money("cash",500);
	carry_object("/open/magic-manor/soil/obj/soil-claw")->wield();
}

void heart_beat()
{
    object mob,me,obj;
	mixed enemy;
	int i,j=0,k=random(2);
    mob = this_object();
    me = this_player();
    if(!environment(mob)) return ;
	enemy = all_inventory( environment(mob) );
    i = sizeof(enemy);

	if( !mob->is_fighting() || mob->is_fighting() )
	{
	  for (j=0 ; j < i ; j++)
	  {
	    if( !enemy[j] ) continue;
 	    {
 	    if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	    && living(enemy[j]) && !enemy[j]->query("soil-monster") ) 
	    mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if(random(10) > 6 && mob->is_fighting() )
	{
	message_vision(HIM"雷厉风行，惊天动地，横扫万物于须臾，$N感念深刻聚力一指瞬间击出

            "HIW"----===≡◎ 土爆雷霆式 ◎≡===----
                 "NOR+BLU"  ‘"HIB"土假虎威．地雷震"NOR+BLU"’\n\n"NOR,mob);

	  for (j=0 ; j < i ; j++)
	  {
	    if( !enemy[j]) continue;
	    {
	      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
	      && !enemy[j]->query("soil-monster") )
	      {
	        if( !enemy[j]->query_temp("magic-manor/wood-shield") )
	        {
	        message_vision(YEL"$N"YEL"只感呼吸困难，行走不便，只能任由飞沙走石在身上无情的鞭打!!\n"NOR,(enemy[j]));
	        enemy[j]->receive_wound("kee",600);
	        COMBAT_D->report_status(enemy[j]);
	        }else{
	        message_vision(HIG"$N"HIG"身上的木灵之气缓和了部份的飞沙走石冲击!!\n"NOR,(enemy[j]));
	        enemy[j]->receive_wound("kee",300);
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

	if( !me->query_temp("magic-manor/soilmagic") )
	{
	message_vision(YEL"土爆波死后的灵魂忽然化为一道土色灵光，灌入了$N"YEL"的身体之中!!\n"NOR,me);
	me->set_temp("magic-manor/soilmagic",1);
	}
	me->delete_temp("magic-manor/breaksoil",1);
    message_vision("\n\n塔身因为土灵王的灭亡而慢慢的出现了一些裂痕.....\n",me);

	:: die();
}
