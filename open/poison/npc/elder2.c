#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_ask();
string poison_help();
string give_key();
void create()
{
        set_name("执法大长老",({"elder"}));
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
        set("int", 50);
        set("force",650);
        set("max_force",650);
        set_skill("dodge",70);
        set_skill("parry",60);
        set_skill("poison",100);
        set_skill("coldpoison",60);
        set_skill("unarmed",40);
        set_skill("whip",60);
        set_skill("ming-snake",40);
        set_skill("nine-steps",30);
        map_skill("whip","ming-snake");
        map_skill("dodge","nine-steps");
        map_skill("poison","coldpoison");
	set("chat_chance_combat",60);
	set("chat_msg_combat",({
	(: perform_action,"poison.five" :),
	(: perform_action,"poison.dark" :),
	}));
        set("force_factor",5);
        set("inquiry",([
        "赵青云" : (: poison_help :),
        "入教"   : (: do_ask :),
        "石牢"   : (: give_key :),
        "赤火令" : "那是平时教主用于传令之用。\n",
        ]));

        setup();
        carry_object(POISON_OBJ"stonekey");
        carry_object(POISON_OBJ"green_whip")->wield();
        carry_object("/obj/poison/rose_poison")->set_amount(30);
        carry_object("/obj/poison/five_poison")->set_amount(30);
        carry_object("/obj/poison/dark_poison")->set_amount(30);
}
void init()
{
     add_action("do_swear","swear");
}

string poison_help()
{
   object me = this_player();
   if(me->query_temp("poison_help") < 2)
        return "我不知道你在说些什么?\n" ;
   if(!present("firer",me))
        return "我只奉教主令行事，看来你身上并无赤火令。\n";
   message_vision(HIC"$N出示身上令牌，两旁使者急忙跪接。\n",me);
   return "教主要找之人想必就是前些日子被我囚禁于石牢之人。\n";
}
string give_key()
{
   object me = this_player();
   object key = new("/open/poison/obj/stonekey");
   if(me->query_temp("poison_help") < 2 && me->query("lotch") !=5)
        return "我不知道你在说些什么?\n" ;
   if(!present("firer",me))
        return "我只奉教主令行事，看来你身上并无赤火令。\n";
   key->move(me);
   command("say 石牢便是在此地东南方的石洞内。\n");
  message_vision(HIC"长老交给$N一把石钥匙。\n",me);
   return "那是一把能引动石门开关的磁石。\n" ;
}

string do_ask()
{
   object me=this_player();
   if(!me->query_temp("poison_pass1")){
        return "你先过问其他长老吧。\n" ;
       }
   else {
     command("smile");
     command("say 既然大长老已经同意了，我也不为难你。");
     me->set_temp("elder2_temp",1);
     return "你就在此宣誓(swear)守教规吧。\n" ;
    }
}
int do_swear(string str)
{
   object who = this_player();
   if(who->query_temp("elder2_temp")){
         if(str=="守教规"){
            who->set_temp("poison_pass2",1);
            message_vision(sprintf(HIC"$N发誓说道："+str+"\n"NOR),who);
            command("say 很好，很有诚意，我这就答应你。");
            command("say 要好好遵守教规哦。");
            command("say 你可以去教主那边入教(join)了。");
            who->delete_temp("elder2_temp");
            return 1;
           }
         else {
           message_vision(sprintf(HIC"$N发誓说道："+str+"\n"NOR),who);
           command("say 你发的是什么誓？");
           command("say 算了，你还是回去吧。");
           who->delete_temp("elder2_temp");
           return 1;
          }
     }
    message_vision(sprintf(HIC"$N发誓说道："+str+"\n"),who);
    command("say 你发什么誓呀，我有同意吗？");
  return 1;
}

