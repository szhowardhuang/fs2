#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
string book();
string ask_sec()
{
	if( !this_player()->query("quests/to-kill-1") )
		return "你在说些什么 ?\n";
	this_player()->set("quests/to-kill-2",1);
	return "好吧 ! 我就告诉你好了 ! 黑仙罗汉就是李灵 !\n";
}
int do_check( object me )
{
	command("say "+(me->query("gender")=="男性" ? "壮士" : "姑娘")+" ! 你看了似乎受到了极重的内伤，让我替你看看吧 ?");
}
int do_nod()
{
	object me = this_player() , ob = this_object();
	if( !me->query("quests/kill-dugur") || me->query("quests/cure-star") ) return 0;
	message_vision("$N看了看$n身上的伤痕。\n",this_object(),this_player());
	command("sign");
	command("say 老夫无能为力，伤你之人的根基远在老夫之上，当今世上，恐怕只有郑士欣有这种实力。");
	command("say 快去找他来帮你看「你的伤”并请他帮你「疗伤”。");
	return 1;
}
void create()
{
           set_name("刘全书",({"master liu","liu"}));
          set("long","他是雪苍三侠之首‘黑影鬼脚’刘全书，一双铁脚，纵横武林。\n");
		set("gender","男性");
	set("guild_master",1);
	set("class","fighter");
          set("nickname","黑影鬼脚");
          set("combat_exp",1000000);
          set("attitude","heroism");
          set("age",47);
          set("title","雪苍派第四代掌门人");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
          set("force",2200);
          set("max_kee",1500);
          set("kee",1500);
          set("inquiry",([
                 "天邪石":   "师父临终前曾交给我这样宝物，他说此物当赠与有缘人。",
        "有缘人":   "能说出十年前武林三大高手者，即为有缘人。\n",
      "藏经阁":  (: book :),
	"玉门关" : (: ask_sec :),
	"去老还童术" : "这个是一个古老的传说，但是我从来就没有看过。\n",
	"神算先生" : "此人身负奇才，有预知「未来”之能。\n",
          ]));
            set_skill("literate",40);
          set("max_force",2200);
	set_skill("array",40);
	set_skill("blade",60);
	set_skill("cure",40);
	set_skill("dagger",20);
	set_skill("move",70);
	set_skill("force",120);
	set_skill("magic",20);
	set_skill("dodge",80);
	set_skill("parry",60);
	set_skill("poison",20);
	set_skill("staff",50);
	set_skill("stick",50);
	set_skill("sword",60);
	set("functions/enforceup/level",30);
	set("functions/kee-wind/level",30);
	set_skill("throwing",60);
	set_skill("spells",20);
	set_skill("unarmed",100);
	set_skill("whip",40);
	set("force_factor",10);
	set_skill("parry",60);
	set_skill("snowforce",100);
	map_skill("force","snowforce");
	set_skill("black-steps",80);
	set_skill("snow-martial",100);
	map_skill("unarmed","snow-martial");
	map_skill("dodge","black-steps");
	set("chat_chance_combat",60);
	set("chat_msg_combat",({
	(: exert_function, "enforceup" :),

	(: perform_action, "unarmed.kee-wind" :)
	}));
	setup();
          create_family("雪苍派",4,"掌门人");
	carry_object(SNOW_OBJ"stone");
        carry_object(SNOW_OBJ"figring")->wield();
	carry_object(SNOW_OBJ"liucloth")->wear();
}

void init()
{
	object me = this_player();
	if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
		call_out("do_check",1,me);
      add_action("do_say","say");
	add_action("do_nod","nod");
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if(this_player()->query("class")!="fighter")
	{
		command("say 你不是武者，我不能收你。\n");
		return;
	}
      if((int)ob->query("str")<20) {
          command("say 雪苍鬼脚要力量大的人才能学，我看你请回吧!\n");
	  return;
      }
      command("hmm");
      command("recruit "+ob->query("id"));
}

int do_say(string str)
{
     object who;
        who=this_player();
	if(who->query("get_stone")==1)
           return 0;
    if (str=="黄云")  this_player()->set_temp("say_1",1);
    if (str=="陈蝶衣")    this_player()->set_temp("say_2",1);
    if (str=="复活邪神")  this_player()->set_temp("say_3",1);
    if(this_player()->query_temp("say_1")==1&&this_player()->query_temp("say_2")==1&&this_player()->query_temp("say_3")==1)
     {
      command("smile");
        command("say 你果然是有缘人。\n");
      command("drop stone");
	this_player()->set("get_stone",1);
      }
    return 0;
}
string book()
{
   object me=this_player();
   if(me->query("allow_study")==1)
          return "嗯...不是跟你说过了吗？\n";
   command("say 此乃本派藏书重地，里面有本派重要秘笈。");
   if(me->query("family/family_name")!="雪苍派")
              return "你不是本派的弟子，没资格读本派的书。\n";
   if(me->query("combat_exp")<25000)
         return "已你这种程度要读藏经阁的书，还早的很。\n";
   me->set("allow_study",1);
   return "好吧！我准你读藏经阁内的书，但是雪苍秘录、鬼影脚秘笈、和黑影残风录三本书只准读一本，而且读一次。\n";
}
int do_join()
{
	if(this_player()->query("class"))
		return notify_fail("你已经加入其他工会了。\n");
	this_player()->set("class","fighter");
	message("system",
	HIC "天生英才.....\n\n一代武者"+this_player()->name()+"诞生了 !!!\n" NOR,users());
	return 1;
}
