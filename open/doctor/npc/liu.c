#include <ansi.h>
inherit NPC;
void create()
 {
        set_name("刘进泉",({"chuan liu","chuan","liu"}));
        set("long","
  他是银针门掌门的大徒弟。对于医术也津津乐道。
");
        set("gender","男性");
        set("class","doctor");
        set("nickname","无影针");
        set("combat_exp",550000);
        set("attitude","heroism");
        set("age",35);
        set("title","银针门首徒");
        set("str",19);
        set("cor",24);
        set("cps",29);
        set("per",20);
        set("int",17);
        set("con",20);
        set("spi",26);
        set("kar",20);
        set("force",1200);
        set("max_force",1200);
        set("force_factor",10);
        set_skill("move",40);
        set_skill("literate",40);
        set_skill("cure",60);
        set_skill("godcure",70);
        set_skill("dagger",40);
        set_skill("poison",50);
        set_skill("force",50);
        set_skill("dodge",60);
        set_skill("parry",40);
        set_skill("unarmed",40);
        set_skill("hammer",40);
        set_skill("shinnoforce",50);
        set_skill("stabber",60);
        set_skill("yu-needle",80);
        map_skill("cure","godcure");
        map_skill("stabber","yu-needle");
        map_skill("parry","yu-needle");
set_skill("seven-steps",60);
map_skill("dodge","seven-steps");
map_skill("move","seven-steps");
        map_skill("force","shinnoforce");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            HIY"刘进泉说道: 真的要打吗? 你恐怕不是我的对手吧!\n"NOR,
            HIY"刘进泉说道: 就让你嚐嚐苦头吧! 好让你知道天有多高地有多厚!\n"NOR,
      }));

        setup();

        carry_object("/open/doctor/obj/needle6.c")->wield();
        add_money("gold",5);
 }
void greeting(object ob)
{
        if( (string)ob->query("class") == "poisoner" )
{
        command("say 师父生平最恨毒害苍生之人,今日我便为师除害,纳命吧！");
        kill_ob(ob);
}
}

