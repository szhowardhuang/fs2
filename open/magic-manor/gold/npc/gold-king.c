inherit NPC;
#include "/open/open.h"
#include <ansi.h>
string do_special_fight();

void create()
{
        set_name("金极飘", ({ "golden king","golden","king" }) );
        set("long","金灵塔的镇塔之王，能力比小金妖和金灵兽不知强上几倍。\n");
        set("title",HIY"(金色灵气)"NOR"金灵塔王"NOR);
	set("gender","男性");
        set("age", 60);
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
        set("str", 35);
        set("cor", 35);
        set("spi", 35);
        set("int", 35);
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 250);
        set("class","blademan");
        set("env/连击","YES");
        set("bellicosity",10000);
        set("functions/gold-dest/level",100);
        set("functions/fast-dest/level",100);
	set_skill("blade",150);
	set_skill("fast-blade",150);
	set_skill("gold-blade",150);
	set_skill("nine-steps",150);
	set_skill("move",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("force",150);
	set_skill("sixforce",150);
	map_skill("dodge","nine-steps");
	map_skill("move","nine-steps");
	map_skill("parry","gold-blade");
	map_skill("blade","fast-blade");
	map_skill("force","sixforce");

	set("combat_exp", 8000000);
	set("gold-monster",1);
        set("chat_chance_combat",50);
        set("chat_msg_combat",({   (: do_special_fight :)   }) );
        setup();
        create_family("金刀门", 6, "弟子");
	add_money("cash",500);
	carry_object("/open/magic-manor/gold/obj/golden-blade")->wield();
}

void heart_beat()
{
    object mob,me,obj;
	mixed enemy;
	int i,j=0,k=random(2);
    mob = this_object();
    me = this_player();
	enemy = all_inventory( environment(mob) );
    i = sizeof(enemy);

	if( !mob->is_fighting() || mob->is_fighting() )
	{
	  for (j=0 ; j < i ; j++)
	  {
	    if( !enemy[j] ) continue;
 	    {
 	    if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	    && living(enemy[j]) && !enemy[j]->query("gold-monster") ) 
	    mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if(random(10) > 6 && mob->is_fighting() )
	{
   	  message_vision(HIM"\n夕阳残照，暮色泛起，余晖映照于大地，$N感受如此无限晚意轻轻带出

            "HIW"----===≡◎ 金封大地式 ◎≡===----
                 "NOR+YEL"  ‘"HIY"金灵蛇动．残阳坠"NOR+YEL"’\n\n"NOR,mob);
          for (j=0 ; j < i ; j++)
          {
	    if( !enemy[j] ) continue;
	    {
              if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
              && !enemy[j]->query("gold-monster") )
              {
		if( !enemy[j]->query_temp("magic-manor/fire-shield") )
		{
		message_vision(HIY"$N"HIY"只感一阵头痛欲裂，震耳欲聋，七孔流出丝丝血迹!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",600);
		enemy[j]->start_busy(1);
		COMBAT_D->report_status(enemy[j]);
		}else{
		message_vision(HIR"$N"HIR"身上的火灵之气缓和了部份的招式冲击!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",300);
		enemy[j]->start_busy(k);
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

	if( !me->query_temp("magic-manor/goldmagic") )
	{
	message_vision(HIY"金极飘死后的灵魂忽然化为一道金色灵光，灌入了$N"HIY"的身体之中!!\n"NOR,me);
	me->set_temp("magic-manor/goldmagic",1);
	}
	me->delete_temp("magic-manor/breakgold",1);
    message_vision("\n\n塔身因为金灵王的灭亡而慢慢的出现了一些裂痕.....\n",me);

	:: die();
}

string do_special_fight()
{

        if( query_skill_mapped("blade") == "fast-blade" ) {
            command("perform blade.fast-dest");
            map_skill("blade", "gold-blade");
        }
        else if( query_skill_mapped("blade") == "gold-blade" ) { 
            command("perform blade.gold-dest");
            map_skill("blade", "fast-blade");
        }
        command("perform blade.gold-dest");
        return "";
}

