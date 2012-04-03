#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("雷一鸣",({"master blademan","master","blademan"}));
        set("long","一个虎臂雄腰的彪型大汉，为天下刀客之首。\n");
        set("gender","男性");
        set("class","blademan");
        set("nickname","狂霸刀");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("guild_master",1);
        set("age",37);
        set("title","刀客公会大长老");
        set("str", 60);
        set("cor", 40);
        set("cps", 30);
        set("per", 24);
        set("int", 42);
        set("force",2000);
        set("max_force",2000);
        set_skill("move",60);
        set_skill("force",90);
        set_skill("dodge",60);
        set_skill("parry",90);
        set_skill("literate",60);
        set_skill("blade",120);
        set("force_factor",15);
        setup();
        carry_object("/daemon/class/blademan/obj/nine-blade")->wield();
        add_money("gold",10);
}

void init()
{
        add_action("do_join","join");
}
int do_join()
        {
        if(this_player()->query("class")=="blademan")
        return notify_fail("你已经是刀客啰 !\n");
        if(this_player()->query("class"))
        return notify_fail("你已经加入其他工会了。\n");
        this_player()->set("class","blademan");
        message("system",HIY "雷一鸣纵声大笑：\n
我们刀客又多了个生力军" +this_player()->name()+ "啰！\n
各位伙伴们，一起欢迎他吧！\n\n"NOR,users());
        command("smile "+this_player()->query("id"));
        command("say 希望你能好好努力，壮大我刀客阵容！\n");
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
	  new("/open/sky/obj10/palm_yin")->move(environment(winner));
	  message_vision(HIM"\n从雷一鸣的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/palm_yin",sprintf("%s(%s) 让雷一鸣掉下了棕灵之印于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/palm_yin")->move(environment(winner));
	  message_vision(HIM"\n从雷一鸣的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/palm_yin",sprintf("%s(%s) 让雷一鸣掉下了棕灵之印于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();                                                           
}

