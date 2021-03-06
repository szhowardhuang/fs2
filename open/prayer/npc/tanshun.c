#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
void create()
{
        set_name("司徒知华", ({"se-tu hua","se-tu","hua"}));
        set("long",@LONG

        天璇门的门主！是天权门主司徒荣的元配，其祖乃是中原战国
        时期的名门将相．与夫婿两人在教主的垂爱之下，一同加入圣
        火教．司徒知华在内功方面的修为非常专一，对圣火教的镇教
        武学--浑天宝鉴已经修练的炉火纯青!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏升");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",44);
        set("title","天璇门主");
        set("kee",5400);
        set("max_kee",5400);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",3800);
        set("max_sen",3800);
        set("force_factor",10);
        set_skill("holy-force", 70);
        set_skill("superforce", 80);
        set_skill("cure",60);
        set_skill("dodge", 60);
        set_skill("force",70);
        set_skill("move", 60);
        set_skill("parry", 80);
        set_skill("canon", 80);
        set_skill("unarmed",70);
        set_skill("literate",60);
        set_skill("shift-steps",60);
        set_skill("universe",60);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/goldsun/level",40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.sun2") :),
        (: exert_function("goldsun") :),
        }));
        setup();
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/speed-ring")->wear();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    add_money("gold",5);
    create_family("天璇门",5,"门主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_4"))
        {
        command("say 没有教主的同意,我不敢擅自做主让你进门!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就进入我天璇门吧!");
        command("say 浑天心法博大精深,可不是那么好学的!");
        command("say 想学浑天心法就得好好修习内功的基础!");
        command("recruit "+ob->query("id"));
        ob->set("marks/圣火八天门",1);
        this_player()->set("title","圣火教天璇门俗家弟子");
        }

int accept_kill(object ob)
{
        ob->set_temp("杀妻之仇",1);
        command("say 哼!!"+ob->name()+"我夫婿会替我报仇的。");
        return 1;
}

void greeting(object ob)
{
        if( ob->query_temp("杀夫之仇") )
        {
        command("angry "+getuid(ob));
        command("say 还我先夫[司徒荣]的命来!!!!");
        kill_ob(ob);
        return;
        }

        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        command("say 教主有令！！凡是学有毒术之人，杀无敕！！");
        kill_ob(ob);
        return;
        }
        if( ob->query("class")=="dancer")
        {
        command("say 教主有令，见到舞者-----格杀勿论！！");
        kill_ob(ob);
        return;
        }
        return;
}
