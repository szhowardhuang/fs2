#include <ansi.h>
#include <command.h>
inherit NPC;
void do_heal();
void create()
{
        set_name("万镜龄",({"master waung","master","waung"}) );
        set("long","他是银针门的副门主,以精湛的医术独步武林,以济世救人为宗旨。");
        set("gender","男性");
        set("class","doctor");
        set("nickname","济世救人");
        set("combat_exp",800000);
        set("attitude","heroism");
        set("age",66);
        set("title","银针门副门主");
        set("str",15);
        set("cor",40);
        set("force",4000);
        set("max_force",4000);
        set("kee",2800);
        set_skill("literate",70);
        set("max_kee",2800);
        set_skill("cure",80);
        set_skill("dodge",80);
        set_skill("move",60);
        set_skill("parry",80);
        set_skill("stabber",60);
        set_skill("poison",60);
        set_skill("force",50);
        set_skill("magic",30);
        set_skill("unarmed",40);
        set_skill("yu-needle",80);
        set_skill("seven-steps",90);
        set_skill("godcure",80);
        set_skill("shinnoforce",60);
        map_skill("stabber","yu-needle");
        map_skill("dodge","seven-steps");
        map_skill("parry","yu-needle");
        map_skill("move","seven-steps");
        map_skill("force","shinnoforce");
        map_skill("cure","godcure");
        set("force_factor",10);
        set("chat_chance_combat",60);
        set("functions/break-kee/level",50);
        set("chat_msg_combat",({
        (: perform_action("stabber.break-kee") :),
        (: do_heal :)
        }));
        setup();
        carry_object("/open/doctor/obj/needle8.c")->wield();
        carry_object("/open/doctor/obj/cloth2.c")->wear();
        add_money("gold",10);
}

void do_heal()
{
        message_vision("万镜龄见情势不妙，赶紧拿起针来往自己的身上扎了几下。\n",this_object());
        this_object()->add("kee",400);
        }

void greeting(object ob)
{
        if( (string)ob->query("class") == "poisoner" )
{
        command("say 老夫生平最恨毒害苍生之人,今日我便为民除害,纳命吧！");
        kill_ob(ob);
}
}


