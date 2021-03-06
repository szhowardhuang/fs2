#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
inherit SSERVER;
object ob1=this_object();
string do_crystal();
string do_help()
{
    object ob2=this_player();
    if( !ob2->query_temp("杀害人犯") && !ob2->query_temp("can_tell",1)  )
    {
    return(" [36m阁下并非我圣火教的执法者, 恕在下甚难从命!![0m\n");
    }
    ob2->delete_temp("can_tell");
    ob2->set_temp("can_go",1);
    return(" 哼!他害我因此无法完成教主交待的任务,我实在无法原谅他..\n
    除非.........\n");
}

string do_else()
{
    object ob2=this_player();
    if( !ob2->query_temp("can_go",1) && !ob2->query_temp("杀害人犯") )
    {
    return("  在下不愿多谈此事!!阁下请回吧!!");
    }
    ob2->delete_temp("can_go");
    ob2->set_temp("will_go",1); 
    return(" 你去帮我完成这个任务,我就放了他!!愿意吗(nod)??\n");
} 

string ask_water()
{
    object ob=this_player();
    if(!ob->query_temp("ask_hurted") && !ob->query_temp("can_pass"))
    {
    return(" 请恕在下无礼!!阁下似乎无权过问我教中武学之事!!\n");
    }
    ob->delete_temp("ask_hurted");
    ob->set_temp("can_take",1);
    return(" 教主吩咐要我去将白水晶从囹圄池中拿出来!!\n");
}

string do_crystal()
{
    object ob2=this_player();
    object ob3;
    if( ob2->query("quests/white-crystal",1) && !present("white-crystal",ob2) )
    {
    ob3=new("/open/prayer/obj/crystal1");
    ob3->move(this_player());
    return("白水晶是你找回来的, 教主特地破例让你学学上面的心法!!\n");
    } 
    else
    {
    return("唉!!白水晶到现在还是下落不明啊!!真是急死我了!!");
    }
} 

void create()
{
        set_name("司马锦", ({"sema ching","ching"}));
        set("long",@LONG

        天机门的门主，在圣火教中素来有        [武学奇才]的称号．好学
        不倦！对于各种的书籍均好涉猎！个性沉稳，内心细腻，是八
        天门各门主所公认的大哥．武学所及，对于外家兵器与内功均
        有所长．

LONG);
        set("gender","男性");
        set("class","prayer");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",48);
        set("nickname","武学奇才");
        set("title","天机门主");
        set("kee",4500);
        set("max_kee",4500);
        set("force",9000);
        set("max_force",9000);
        set("force_factor",5);
        set("max_gin",3500);
        set("max_sen",3500);
        set_skill("holy-force", 70);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge", 70);
        set_skill("force",70);
        set_skill("canon",70);
        set_skill("move", 50);
        set_skill("parry", 70);
        set_skill("unarmed",70);
        set_skill("literate",60);
        set_skill("shift-steps",70);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/black/level",40);
        set("inquiry",([
        "人犯":"那名人犯竟敢擅自将人犯虐待至死,所以被我关在地牢之内反省!!\n",
        "求情":(: do_help :),
        "除非":(: do_else :),
        "拳师":"拳师是我派去洞窟的, 因为教主给了我一个任务!!\n",
        "任务":"是拿一根浑天水晶!!\n",
        "浑天水晶":"是白色的浑天水晶, 上面是记载基本心法的!!\n",
        "白水晶":(: do_crystal :),
        "囹圄池":(: ask_water :),
        ]));
        set("chat_chance",3);
        set("chat_msg", ({
        HIC+"司马锦朗道:临名而让名～求名当求万世名～!!\n\n"+NOR
        HIC+"临利而让利～计利当计天下利～!!\n\n"+NOR,
        HIC+"戒慎恐惧～居万尘而不染一尘～!!\n\n"+NOR
        HIC+"临渊履薄～理万理而不失一机～!!\n\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: exert_function("black") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
    create_family("圣火教",5,"天机门主");
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob =this_player()) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        add_action("do_nod","nod"); 
        }
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_1"))
        {
        command("say 没有教主的同意,我不敢擅自做主让你进门!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,以后你就跟我好好学吧!");
        command("recruit "+ob->query("id"));
        ob->set("marks/圣火八天门",1);
        this_player()->set("title","圣火教天机门俗家弟子");
}

int do_nod()
{
  object ob2=this_player();
  if( !ob2->query_temp("will_go",1))
  {
  return 0;
  }
  else
  {
  ob2->delete_temp("will_go");
  ob2->set_temp("can_pass",1);
  write(" 妳去找卖鱼的老妇吧!!她会教你如何进入洞窟的!!\n");
  return 1;
  }
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
            
