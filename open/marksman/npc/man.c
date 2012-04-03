#include <ansi.h>
#include </open/open.h>

inherit NPC;
void create()
{
        set_name("平民", ({ "man" }) );
        set("gender", "男性" );
        set("age",30);
        set("str",35);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "一位住在长沙城城的老百姓，每天正在努力的工作。\n");
set("combat_exp",5000);
set("max_kee",3400);
        set("attitude", "peaceful");
        set_skill("parry", 15);
        set_skill("dodge", 5);
        set("chat_chance", 30);
        set("chat_msg", ({
        "平民唉气的说：每天都要去工作好烦喔。\n",
        }) );

        setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
        carry_object(COMMON_OBJ"pill");
}

int accept_kill(object ob)
{
 command("say 连我这个平民百姓你也想要杀，你真是猪狗不如!");
 command("say 我拼了命也要杀了你，受死吧!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("hmm");
command("say 最近都没有在运动，就陪你玩一下下当在运动。");
return 1;
}
