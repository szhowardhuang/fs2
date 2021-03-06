#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	set_name("郑士欣",({"master teng","teng","master"}));
set("long","他就是武林第一大宗师 :郑士欣 .现正执掌仙剑门户 .
同时身为剑士公会总会长 .近十余年来 ,因仙剑七侠已
能独当一面 ,分担派内事务 .而公会事务也由三长老柳
毅全权负责 ,郑士欣每天除了至藏经阁精研武学外 ,就
是在此接见外宾 .\n");
		set("gender","男性");
	set("class","swordsman");
	 set("nickname","无极真人");
          set("combat_exp",1000000);
          set("attitude","heroism");
	  set("age",76);
	set("title","仙剑派第三代掌门人");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",3000);
	set_skill("literate",80);
       set_skill("shasword",100);
      set_skill("shaforce",100);
      set_skill("sha-steps",80);
	set("max_force",3000);
	set_skill("array",100);
	set_skill("move",80);
	set_skill("force",60);
	set_skill("dodge",90);
	set_skill("parry",100);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
	set_skill("sword",120);
        map_skill("force","shaforce");
        map_skill("sword","shasword");
	set_skill("unarmed",60);
	set_skill("whip",100);
	set_skill("blade",40);
	set_skill("spells",40);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("shasword",100);
	map_skill("sword","shasword");
	map_skill("parry","shasword");
	set_skill("cure",60);
	set_skill("dagger",40);
	set("force_factor",10);
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
	(:exert_function,"swordkee":)
	}));
	setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
	carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
	add_money("gold",10);
	create_family("仙剑派",3,"掌门人");
}

void init()
{
     /*
	add_action("do_join","join");
    */
	add_action("do_select","select");
}
  void attempt_apprentice(object ob)
{
	if(ob->query("marks/仙剑七侠")==1)
	{
	if((int)this_player()->query("combat_exp")<=100000)
	{
	command("? " +ob ->query("id"));
	command("say 你不是拜过我的弟子了?");
	command("say 以你的程度还不须我亲自指导!");
	command("say 好好跟着你师父多学几年吧!");
	return 0;
	}
	command("look "+ob->query("id"));
	command("smile");
	command("say 好,你果然是可造之才,从今后就由老夫亲自指导!");
	command("recruit "+this_player()->query("id"));
	message("system",HIW"郑士欣纵声大笑: 
哈哈哈哈....老夫实在太高兴啦!
英雄出少年 ,"+this_player()->name()+": 今后就由老夫亲授于你.\n"NOR,users());
	return ;
	}
      command("hmm");
	command("say 我老啦 ,你去拜我的七个徒弟吧 !");
	command("say 你想拜(select)谁呢?");
	ob->set_temp("allow_select",1);
}
int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("你已经加入其他工会了。\n");
	this_player()->set("class","swordsman");
	message("system",HIW "郑士欣纵声大呼 :\n
欢迎" +this_player()->name()+"加入剑士公会!!\n\n"NOR,users());
	return 1;
}
	int do_select(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又没答应让你挑? ");
	return 1;
	}
	if(who->query_temp("have_say")==1)
	{
	message_vision(sprintf(HIC"$N说道："+str+"\n"NOR),who);
	command("say 你不是挑过了?");
	return 1;
	}
	if(str=="张乘风" ||  str == "chen fon" || str == "fon")
        {
	 message_vision(HIC"$N说道：张乘风\n"NOR,who);
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就拜我的首徒张乘风吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "张乘云" || str == "chen un" || str == "un")
	{
	message_vision(HIC"$N说道：张乘云\n"NOR,who);
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒张乘云吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "范松" || str == "fan son" || str == "son")
	{
	message_vision(HIC"$N说道：范松\n"NOR,who);
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子范松吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "赵鹤" || str == "san hu" || str == "hu")
	{
	message_vision(HIC"$N说道：赵鹤\n"NOR,who);
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子赵鹤吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "梁发" || str == "lian fa" || str == "fa")
	{
	message_vision(HIC"$N说道：梁发\n"NOR,who);
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的五弟子梁发吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "何双双" || str == "cute girl" || str == "girl")
	{
	message_vision(HIC"$N说道：何双双\n",who);
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何双双吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	if(str == "李逍遥" || str == "shou_yau" || str == "yau")
	{
	message_vision(HIC"$N说道：李逍遥\n"NOR,who);
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遥吧!");
	this_player()->set_temp("have_say",1);
	return 1;
	}
	command("say 没这人!");
	return 1;
	}
