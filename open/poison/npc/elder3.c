#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_ask();
void create()
{
        set_name("传功大长老",({"elder"}));
        set("title","冥蛊魔教长老");
        set("gender","男性");
        set("class","poisoner");
        set("combat_exp",73632);
        set("attitude","heroism");
        set("age",60);
        set("str", 40);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 45);
        set("force",650);
        set("max_force",650);
        set_skill("dodge", 70);
        set_skill("parry",60);
        set_skill("coldpoison",60);
        set_skill("poison",100);
        set_skill("unarmed",40);
        set_skill("whip",60);
        set_skill("nine-steps",30);
        set_skill("ming-snake",40);
        map_skill("dodge","nine-steps");
        map_skill("poison","coldpoison");
        map_skill("whip","ming-snake");
        set("chat_chance_combat",60);
        set("chat_msg_combat",({
        (: perform_action,"poison.five" :),
        (: perform_action,"poison.dark" :),
        }));
        set("force_factor", 5);
        set("inquiry",([
        "月石":   (: do_ask :),
        ]));

        setup();
        carry_object(POISON_OBJ"green_whip")->wield();
        carry_object("/obj/poison/five_poison")->add_amount(30);
        carry_object("/obj/poison/rose_poison")->set_amount(30);
        carry_object("/obj/poison/faint_poison")->set_amount(30);
        carry_object("/obj/poison/dark_poison")->add_amount(30);
}

void init()
{
        add_action("do_say","say");
}
string do_ask()
{
        object me=this_player();
        command("hmm");
       if(!me->query_temp("moon-stone"))
                return "你问这干麻？";
        me->set_temp("moon-stone",2);
        return "喔？你是啥来头？ ";
}
int do_say(string str)
{
  object me = this_player();
  string myclass=me->query("family/family_name");

  if(me->query_temp("moon-stone",2)){
        if(str == "镖师" )
          {
            me->set_temp("moon-stone",3);
            me->delete_temp("moon-stone",2);
            command("smile");
            command("say 我等你好久了。");
            command("say 快将月石交给敛帮主。");
            new("/open/poison/obj/moon.c")->move(me);
            return 1;
          }
        else
           {
            command("say 哼！原来是奸隙。受死吧！");
            me->delete_temp("mmon-stone");
            kill_ob(me);
           }
        return 0;
   }
}
