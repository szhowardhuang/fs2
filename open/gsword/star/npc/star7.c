#include <ansi.h>
inherit NPC;

void create()
{
   set_name("瑶光楼主 翼宿 ", ({"starman"}));
        set("long","仙剑派七星塔之守塔士, 目前正守卫着七星塔.\n");
        set("gender","男性");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",31);
        set("class","swordsman");
        set("score",1000);
        set("force",3000);
        set("max_kee", 3000);
        set("max_force",3000);
        set("force_factor",10);
        set("str",30);
        set("cor", 30);
        set("per", 25);
        set("int", 30);
        set("cps",20);
        set("con", 30);
        set("spi", 15);
        set("kar", 30);
        set_skill("sword",100);
        set_skill("dodge",80);
        set_skill("parry",100);
        set_skill("shasword",100);
        set_skill("force",80);
        set_skill("shaforce",100);
        set_skill("sha-steps",80);
        map_skill("dodge","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","shasword");
        set("inquiry",([
"丽玉蝶兰" : "这这这........你大那知道的??????\n",
"诸葛神算" : "这...这个可恶的家伙竟然敢泄漏我们的秘密... !!\n",
"灵笔" : "就是...丽玉蝶兰ㄚ....当初我们有缘得到之后...就一直是七星塔的镇塔之宝 .\n",
]));
        map_skill("parry","shasword");
        setup();
        carry_object("/open/gsword/star/obj/sword1")->wield();
        add_money("gold",5);
carry_object("/open/gsword/star/obj/starhat")->wear();
}
 int accept_fight(object me)
  {
  if((int)me->query("combat_exp")<=300000)
  {
   command("say 你的能力不足, 下次在来切磋吧!");
   return 0;
  }
  command("say 你的技巧不错, 来切磋看看!");
  return 1;
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
	  new("/open/sky/obj5/uiw_jade")->move(environment(winner));
	  message_vision(HIM"\n从翼宿的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/uiw_jade",sprintf("%s(%s) 让翼宿掉下了瑶光星玉于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj5/uiw_jade")->move(environment(winner));
	  message_vision(HIM"\n从翼宿的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/uiw_jade",sprintf("%s(%s) 让翼宿掉下了瑶光星玉于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}