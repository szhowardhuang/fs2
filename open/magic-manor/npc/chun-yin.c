#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("纯灵吟",({"chun yin","chun","yin"}));
        set("long",@LONG
聚灵八杰之一，段家功夫朗朗上手，看似文弱无力，但招式之
精奇，却是八杰之最，功夫变幻莫测，招无一定，让人难以捉
摸，虽为女流之辈，却不失为女中豪杰。
LONG);
	set("gender","女性");
	set("class","scholar");
	set("nickname",NOR+YEL"飘"HIY"阳"NOR+YEL"无"HIY"惧"NOR);
	set("title",HIC"聚灵八杰"NOR);
    set("family/family_name","段家");
	set("combat_exp",10000000);
	set("attitude","friendly");
	set("score",1000000);
	set("bellicosity",3000);
	set("age",40);

	set("str", 35);
	set("cor", 35);
	set("cps", 35);
	set("int", 35);
	set("spi", 35);
	set("per", 35);
	set("kar", 35);
	set("con", 35);

	set("env/fan_auto_shoot","YES");
//	set("env/飘阳扇连击","YES");
	set("env/六绝剑","YES");

	set("force",20000);
	set("max_force",20000);
	set("mana",20000);
	set("max_mana",20000);
	set("atman",20000);
	set("max_atman",20000);
	set("force_factor", 15);

	set("max_kee",50000);
	set("max_gin",50000);
	set("max_sen",50000);

	set_skill("sunforce", 250);
	set_skill("fireforce",250);
	set_skill("dodge", 120);
	set_skill("force",250);
	set_skill("move", 120);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("literate",120);
	set_skill("linpo-steps",120);
	set_skill("six-fingers",120);
	map_skill("force","sunforce");
	map_skill("dodge","linpo-steps");
	map_skill("move","linpo-steps");
	map_skill("parry","six-fingers");
	map_skill("stabber","six-fingers");
	map_skill("unarmed","six-fingers");

	set("functions/handwriting/level",100);
	set("functions/fan-finger/level",100);
	set("functions/gold-fire/level",100);

	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.handwriting" :),
	}));

	set("marks/sun-finger",1);
	set("marks/six_sp",3);
	set("six_spsp",1);
	set("quests/sunfire",1);
	set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);
	set("clan_kill",1);
	set("no_hole",1);
	set("no_plan_follow",1);
	set("no_mount",1);
	set_temp("fan-finger",500);
	set_temp("armor_vs_force",300);
	set_temp("no_die_soon",1);
	set_temp("rob",1); 
	set_temp("no-plan",1);
	set_temp("mount",1);
	set_temp("follow",1);
	set_temp("speed",1);
	set_temp("empty",1);
	set_temp("false",1);
	set_temp("lock-link",1);

	set_temp("apply/armor",150);
	set_temp("apply/attack",50);
	set_temp("apply/damage",50);

	setup();

	add_money("cash",300);
	carry_object("/open/magic-manor/obj/lin-cloud-fan");
	carry_object("/open/ping/obj/cloud_fan");
}

int accept_kill(object ob)
{
	object me=this_object();
	kill_ob(ob);
	me->delete_temp("is_busy");
	command("wield all");
	command("perform unarmed.handwriting");
	return 1;

}

void greeting(object ob)
{
	ob=this_player();
	if( ob->query_skill("coldpoison",1) && !wizardp(ob) )
	{
	command("say 学毒术之人，来讨教几招吧！！");
	kill_ob(ob);
	ob->start_busy(1);
	}
	set_heart_beat(1);
	return;
}

void heart_beat()
{
	object me=this_object();

	if( !me->query_temp("weapon") )
	{
	command("wield all");
	command("wear all");
	}

	if( me->is_fighting() && !me->is_busy() )
	{
	command("perform stabber.handwriting");
	}

	if( !me->is_fighting() && !me->query_temp("gold-fire") )
	{
	map_skill("force", "fireforce");
	command("perform force.gold-fire");
	map_skill("force", "sunforce");
	}

	if( me->is_fighting() && !me->is_busy() && !query_temp("finger-rest") )
	{
	command("shoot");
	}

	if( !is_fighting() ) 
	{
	  if( query("force") < 20000 )
	  command( "ex 270" );
	  if( query("eff_kee") < query("max_kee") )
	  {
	  map_skill("force", "fireforce");
	  command( "10 exert heal" );
	  map_skill("force", "sunforce");
	  }
	  if( query("gin") < query("eff_gin") )
	  {
	  me->receive_curing("gin",150);
	  me->receive_heal("gin",150);
	  }
	  if( query("kee") < query("eff_kee") )
	  command( "5 exert recover" );
	  if( query("sen") < query("eff_sen") )
	  {
	  me->receive_curing("sen",150);
	  me->receive_heal("sen",150);
	  }
	}
    set_heart_beat(1);
	::heart_beat();
}

void die()
{
	object me,obj,winner;
	me=this_object();
	winner=query_temp("last_damage_from");

	if(!winner)
	{
	::die();
	return ;
	}
	if( random(9) == 5 )
	{
	obj=new("/open/magic-manor/obj/wood-ball");
	obj->move(environment(winner));
	message_vision(CYN"一颗奇怪的珠子从$N的身体里滚了出来!!\n"NOR,me);
	}else{
	  if( random(12) == 7 )
	  {
	  obj=new("/open/magic-manor/obj/water-ball");
	  obj->move(environment(winner));
	  message_vision(CYN"一颗奇怪的珠子从$N的身体里滚了出来!!\n"NOR,me);
	  }else{
	    if( random(15) == 9 )
	    {
	    obj=new("/open/magic-manor/obj/fire-ball");
	    obj->move(environment(winner));
	    message_vision(CYN"一颗奇怪的珠子从$N的身体里滚了出来!!\n"NOR,me);
	    }else{
	      if( random(18) == 11 )
	      {
	      obj=new("/open/magic-manor/obj/golden-ball");
	      obj->move(environment(winner));
	      message_vision(CYN"一颗奇怪的珠子从$N的身体里滚了出来!!\n"NOR,me);
	      }else{
	        if( random(21) == 13 )
	        {
	        obj=new("/open/magic-manor/obj/soil-ball");
	        message_vision(CYN"一颗奇怪的珠子从$N的身体里滚了出来!!\n"NOR,me);
	        obj->move(environment(winner));
			}
	      }
	    }
	  }
	}
	::die();
}