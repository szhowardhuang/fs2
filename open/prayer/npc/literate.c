#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("骆芝芝", ({"lo chi-chi","lo","chi-chi"}));
        set("long",@LONG

        来自西域南方的土人部落！是部落族长的小女儿，因为小时
        候个性骄矜，我行我素，故自行离开部落四处游乐！后来在
        无意中遇见隐居世外的高人，习得一身的谋略在重返西域后
        ，便投入圣火教的麾下位居军师一职！

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏升");
        set("combat_exp",2000000);
        set("attitude","heroism");
        set("age",35);
        set("nickname","文星君");
        set("title","圣火教军师");
        set("kee",6500);
        set("max_kee",6500);
        set("force",10000);
        set("max_force",10000);
        set("force_factor",25);
        set_skill("cure", 80);
        set_skill("superforce", 95);
        set_skill("holy-force", 100);
        set_skill("dodge", 95);
        set_skill("force",95);
        set_skill("move", 95);
        set_skill("parry",95);
        set_skill("unarmed",100);
        set_skill("array",90);
        set_skill("fire-array",80);
        set_skill("canon",100);
        set_skill("literate",80);
        set_skill("shift-steps",100);
        set_skill("universe",100);
        map_skill("array","fire-array");
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/bluesea/level",60);
        set("chat_chance_combat", 40);
                set("chat_msg_combat", ({
                (: exert_function("bluesea") :),
                (: perform_action("force.bluesea1") :),
                (: perform_action("force.bluesea2") :),
                (: perform_action("force.bluesea3") :),
        }));
        setup();
    add_money("gold",20);
    carry_object("/open/prayer/obj/dragon-robe")->wear();
    carry_object("/open/prayer/obj/dragon-hat")->wear();
    carry_object("/open/prayer/obj/dragon-hands")->wear();
    carry_object("/open/prayer/obj/dragon-icer")->weild();
    carry_object("/open/prayer/obj/dragon-legging")->wear();
    carry_object("/open/prayer/obj/dragon-ring")->wear();
        create_family("圣火教",2,"军师");
}

int accept_fight(object who)
{
  return notify_fail("骆芝芝微笑的说: 我想一个人静一静.\n");

}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_13"))
        {
        command("say 没有教主的同意,我不敢擅自做主收你为入室弟子!");
        return 0;
        }
        command("smile");
        command("say 想要成为一位谋略家是不容易的！");
        command("say 我可是很严格的喔！");
        command("recruit "+ob->query("id"));
        ob->set("marks/文武星君",1);
        this_player()->set("title","圣火教文星君入室弟子");
}

// by ACKY
int accept_kill(object ob)
{
        int i;
        object ob1, hu_fa;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) ) {
        tell_room(environment(ob),HIW"\n突然！冲出两位护法!!\n\n"NOR);
        for(i=0;i<2;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard literate");
        hu_fa->command("follow "+ob->query("id"));
        hu_fa->kill_ob(ob);
	}}
        if( ob->query_temp("lochichi") > 3 ) {
		command("say 哼, 想逃? 没那么容易！\n" );
		ob->delete_temp("lochichi");
		ob->start_busy(1);
	}
	ob->add_temp( "lochichi", 1 );
	message_vision( HIR"护法纵身飞扑过来叫道：大胆狂徒！军师你也敢冒犯！！\n" NOR, ob );
        return 1;
}

void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        command("say 教主有令！！凡是学有毒术之人，杀无敕！！");
        kill_ob(ob);
        }
        if( ob->query("class")=="dancer")
        {
        command("say 教主有令，见到舞者-----格杀勿论！！");
        kill_ob(ob);
     }
    return;
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
	  new("/open/sky/obj4/stable_shells")->move(environment(winner));
	  message_vision(HIM"\n从骆芝芝的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/stable_shells",sprintf("%s(%s) 让骆芝芝掉下了稳定之贝壳于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj4/stable_shells")->move(environment(winner));
	  message_vision(HIM"\n从骆芝芝的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/stable_shells",sprintf("%s(%s) 让骆芝芝掉下了稳定之贝壳于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}