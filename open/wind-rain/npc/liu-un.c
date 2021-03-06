// by roger
inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create() {
        
        set_name("楚流云",({"liu-un"}));
        set("long",@LONG
长期跟在金风细雨楼楼主身边接受指导, 
从一无是处的小毛头蜕变成了绝世高手, 
他的身上还有许多的秘密.
LONG);
        set("age",17);
        set("str",30);
        set("int",30);
        set("spi",30);
        set("cor",30);
        set("kar",30);
        set("cps",30);
        set("race","人类");
        set("gender","雄性");
        set("attitude","peaceful");
        set("class","fighter");
        set("max_gin",3000);
        set("max_kee",4500);
        set("max_sen",3000);
        set("max_force",5000);
        set("force",5000);
        set("force_factor",20);
        set("combat_exp",1000000);
        set_skill("blade",100);
        set_skill("dodge",100);
        set_skill("lo-steps",100);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("wind-rain",100);
        set_skill("literate",150);
        set_skill("sand-blade",100);
        set_skill("force",150);
        map_skill("blade","sand-blade");
        map_skill("dodge","lo-steps");
        map_skill("parry","wind-rain");
        map_skill("move","lo-steps");
        set("clan_kill",1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "\n楚流云说 : 魔刀门把我全家人都杀光了,此仇不共戴天!!\n",
        "\n楚流云说 : 我的救命恩人就是总楼主，水寒星大哥\n",
        "\n楚流云说 : 林静诗姊姊好漂亮喔:D~~\n",
        "\n楚流云说 : 情刀枕梦，心笔叹忆。说的是李梦枕大哥和林静诗姊姊\n",
        "\n楚流云说 : 我的家族两代前是住在西域的\n",
        }) );
        setup();
        carry_object(C_OBJ"/bird-blade")->wield();
        add_money("gold",10);
 }


void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j;

 mob = this_object(); 
 env = environment(mob);
 
 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 mob->delete_busy();
 if( random(100) < 20 && mob->is_fighting())
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
      message_vision(HIW"\n
$N乱舞手中长刀，刀气开始颳起风沙石尘，黄色的雾逐渐弥漫开来
将$N隐在其中，倏然一式"HIY"‘骆行千步归  风沙舞翩翩’"HIW"黄沙杂混着
激烈而灼热的刀气，毫无纹理可寻地向四处围窜
\n"NOR,mob);
 for(j=0;j < i;j++){
    target=enemy[j];
    if( env == environment(target) )
    {
      target->receive_damage("kee",350);
      COMBAT_D->report_status(target, 1);
    }
                   }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}


void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj1/cloud_emblem")->move(environment(winner));
	  message_vision(HIM"\n从楚流云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/cloud_emblem",sprintf("%s(%s) 让楚流云掉下了云之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj1/cloud_emblem")->move(environment(winner));
	  message_vision(HIM"\n从楚流云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/cloud_emblem",sprintf("%s(%s) 让楚流云掉下了云之纹章于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}
