#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{
//	set("title","神秘剑客");
	set_name("神秘剑客", ({"swordsman"}));
	set("age",75);
	set("long","谜一般的神秘男子。\n");
	set("gender","男姓");
	set("str",30);
	set("con",30);
	set("class","fighter");
	set("family/family_name","仙剑派");
	set("bellicosity",1500);
	set("get_sha_sp",1);
	set("no_hire",1);
	set("max_kee",150000);
//	set("attitude","aggressive");
	set("kee",150000);
	set("max_gin",150000);
	set("gin",150000);
	set("max_sen",150000);
	set("sen",150000);
	set("combat_exp",10000000);
	set("max_force",300000);
	set("force",300000);
	set("force_factor",10);
	set("random_move",200);
	set_skill("dodge",120);
	set_skill("force",150);
	set_skill("linpo-steps",100);
	set_skill("unarmed",120);
	set_skill("haoforce",100);
	map_skill("dodge","linpo-steps");
	set_skill("sword",120);
	set_skill("shasword",120);
	map_skill("sword","shasword");
	map_skill("force","haoforce");
    set("chat_chance",100);
    set("chat_msg",({
       (: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"谜说: 无知的后生小辈，看来你是活腻了!!\n",
	"谜说: 哼!就让你看看剑道之最高境界吧!!\n",
	"谜说: 杀杀杀杀!!!\n",
	}));
	set_temp("apply/armor",500);
	set_temp("apply/damage",80);
	set_temp("roared",1);
	setup();
	carry_object("/open/dancer/obj/dsword.c")->wield();
//	add_money("cash",300);
//	set("default_actions", (: call_other, __FILE__,"query_action" :));
	
//	reset_action();
}
void greeting( object ob )
{   
    if( !ob || environment(ob) != environment() ) return;
	if(ob->query("combat_exp")>1000000)
	{    
     write( HIY"神秘剑客说道:死吧....汉人\n"NOR ); 
// command("follow "+ob->query("id"));
	 kill_ob(ob);
	 command("exert roar");
	}
}
void heart_beat()
{
        object *enemy,*all,me;
        int i,j;
        me=this_object();
        j=random(100);
        if(!me) return ;
        if(!environment(me)) return ;
		all=all_inventory(environment(me));
/*		for( i=0 ; i<sizeof(all); i++ )
		    if( living(all[i]) && !is_fighting(all[i]) && all[i]->query("id")!="swordsman" )
		   	kill_ob(all[i]);
        
*/		
          if( j < 25 && is_fighting() )
          {   enemy = me->query_enemy();
            
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
			message_vision(HIW"$N眼露凶光，随着本身杀意的提升‘"HIR"邪剑"HIC"无极"HIW"’之招顿然而出，刹时天地变色，血染尘埃。\n"+NOR,me,enemy[i]);
			enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15);
/*            enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/20);
            enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/20);
*/            COMBAT_D->report_status(enemy[i], 1);
            }
			me->delete_busy();
			me->clear_condition();
          }
		  }
          if( j > 25 && j < 45 && is_fighting() )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW"天地间忽然窜起阵阵火光，$N唸道‘"HIG"天"HIW"、"HIM"离火"HIW"、"HIY"一字"HIR"血"HIY"剑"HIW"’化成一道强烈的剑气贯穿$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/20);
              enemy[i]->receive_damage("sen", enemy[i]->query("max_sen",1)/20);
              enemy[i]->receive_damage("gin", enemy[i]->query("max_gin",1)/20);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 45 && j < 65&& is_fighting()  )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW"$N全身内力不断的注入剑中，使出一招‘"HIB"剑霸四方"HIW"’，剑气中挟带十成功力奋力砍向$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", 2500);
/*              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15);
*/              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 65 && j < 80 && is_fighting() )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIW"$N剑朝天指，‘"HIY"无极"HIG"剑气"HIW"’吸收天地灵气齐聚剑身，宏大的剑劲配合凌厉的剑气迅速刺中$n。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_wound("kee", enemy[i]->query("max_kee",1)/10);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/15);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/15);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
          if( j > 80 && j < 92 && is_fighting()  )
          {
          enemy = me->query_enemy();
            for(i=0;i<sizeof(enemy);i++){
              if(!enemy[i]) continue;
              if(environment(me) == environment(enemy[i]))
              {
              message_vision(HIR"血"HIY"披天色"HIW"，"HIR"魂"HIG"散四方"HIW"，$N体内‘"HIR"血剑"HIB"魔"HIY"气"HIW"’破体而出造成大地崩裂，江河逆流，$n瞬间遭血气掩没。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/15);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
          }
		  if( j> 95 && is_fighting() )
          {
          enemy = me->query_enemy();
            i=random(sizeof(enemy));
              if(enemy[i])
              if(environment(me) == environment(enemy[i]))
              {
			  message_vision(HIR"$N高喊:该死的汉人...看我的无极剑招连击。\n"+NOR,me,enemy[i]);
			  message_vision(HIW"$N眼露凶光，随着本身杀意的提升‘"HIR"邪剑"HIC"无极"HIW"’之招顿然而出，刹时天地变色，血染尘埃。\n"+NOR,me,enemy[i]);
              message_vision(HIW"天地间忽然窜起阵阵火光，$N唸道‘"HIG"天"HIW"、"HIM"离火"HIW"、"HIY"一字"HIR"血"HIY"剑"HIW"’化成一道强烈的剑气贯穿$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIW"$N全身内力不断的注入剑中，使出一招‘"HIB"剑霸四方"HIW"’，剑气中挟带十成功力奋力砍向$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIW"$N剑朝天指，‘"HIY"无极"HIG"剑气"HIW"’吸收天地灵气齐聚剑身，宏大的剑劲配合凌厉的剑气迅速刺中$n。\n"+NOR,me,enemy[i]);
			  message_vision(HIR"血"HIY"披天色"HIW"，"HIR"魂"HIG"散四方"HIW"，$N体内‘"HIR"血剑"HIB"魔"HIY"气"HIW"’破体而出造成大地崩裂，江河逆流，$n瞬间遭血气掩没。\n"+NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", 3000);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10);
			  enemy[i]->start_busy(1);
              COMBAT_D->report_status(enemy[i], 1);
              }
            }
        
  	if( !is_fighting() ) {
		
		if( query("eff_kee") < query("max_kee") ) 
			me->receive_curing("kee",100);
		if( query("eff_gin") < query("max_gin") )
		    me->receive_curing("gin",100);
		if( query("eff_sen") < query("max_sen") )
		    me->receive_curing("sen",100);
		if( query("gin") < query("eff_gin") ) 
			me->receive_heal("gin",100);
		if( query("kee") < query("eff_kee") )
			me->receive_heal("kee",100);
		if( query("sen") < query("eff_sen") ) 
			me->receive_heal("sen",100);
		}
        set_heart_beat(1);
        :: heart_beat();
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;
	j=random(3);
        if(!winner)
	{
	::die();
	return ;
        }

	
	if(j==0)
	{
	  new("/open/dancer/obj/dragon_gem")->move(winner);
	  message_vision(HIM"\n从神秘剑客的身上掉下了一块玉佩!!\n"NOR,winner);
          write_file("/log/get_feq",sprintf("%s(%s) 拿到force gem于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	 }
	  tell_object(users(),HIC"\n\n神秘剑客吼道：\n\n\t"HIW"想不到我流亡边疆苦练多年依然不是"+winner->name()+"的对手！\n\n\t看来中原的能人不少不过我们不会就此罢休的！\n\n"NOR);
	  message_vision(HIY"\n"+winner->name()+"打死神秘剑客得到一百点战功!!\n"NOR,winner);
      write_file("/log/get_warp",sprintf("%s(%s) 得到一百点战功于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  winner->add("war_score",100);
	  
	::die();                                                           
}
