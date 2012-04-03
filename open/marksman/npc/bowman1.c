inherit NPC;
#include <ansi.h>
#include <marksman.h>
void create()
{
        set_name("弓箭教练", ({ "bow coach","bow","coach" }) );
set("class","marksman");
create_family("射日派",3,"教练");
        set("gender", "男性" );
        set("age", 25);
        set("long", "一位正在努力的想要把弓箭生练好的慈善教练。\n");
set("combat_exp",70000);
set("max_kee",800);
        set("max_force",500);
set_skill("archery",60);
set_skill("dodge",60);
set_skill("parry",60);
set_skill("rain-steps",60);
set_skill("iceforce",80);
map_skill("force","iceforce");
set_skill("god-shooting",60);
        map_skill("parry","rain-steps");
        map_skill("archery","god-shooting");
        set_temp("apply/attack",10);
        set_temp("apply/dodge",10);
        set("force_factor",5);
        set("chat_msg",({
        "教练说着：给我把弓箭拿好，没有吃饭呀。 ",
        }));
          setup();
carry_object(C_OBJ"/arrow-5");
carry_object(C_OBJ"/bow-5")->wield();
}
int accept_kill(object ob)
{
 command("say 你是吃了什么东西，敢来杀我!");
 command("say 哼!!!纳命来!!");
command("cmd holdup arrow with bow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 好吧!陪你一下吧。");
command("cmd holdup arrow with bow");
return 1;
}

