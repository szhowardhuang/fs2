#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	   set_name("郑士欣",({"master swordsman","master"}));
set("long","他就是武林第一大宗师 :郑士欣 .现正执掌仙剑门户 ,仙剑虽是
近几十年来的新派 ,但在几任掌门苦心经营下 ,早就名列江湖第
一大派 ,仙剑武学也在几位宗师的钻研 ,整理下 ,构成今日名满
天下的仙剑剑法 ,此套剑法共有八路 ,郑士欣分别传授一路剑法
于仙剑七侠 ,至于这第八路嘛 ...\n");
		set("gender","男性");
	set("guild_master",1);
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
	set("max_force",3000);
	set_skill("array",100);
	set_skill("move",80);
	set_skill("force",60);
	set_skill("dodge",90);
	set_skill("parry",100);
	set_skill("sword",120);
	set_skill("unarmed",60);
	set_skill("whip",100);
	set_skill("blade",40);
	set_skill("spells",40);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("nine-steps",80);
	map_skill("dodge","nine-steps");
	map_skill("move","nine-steps");
	set_skill("shansword",100);
	map_skill("sword","shansword");
	map_skill("parry","shansword");
	set_skill("cure",60);
	set_skill("dagger",40);
	set("force_factor",10);
	setup();
	carry_object("/open/gsword/obj/dragon-sword.c")->wield();
	carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
	add_money("gold",10);
	create_family("仙剑派",3,"掌门人");
}

void init()
{
	add_action("do_join","join");
	add_action("do_say","select");
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
	int do_say(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又没答应让你挑? ");
	return 0;
	}
	if(who->query_temp("have_say")==1)
	{
	command("say 你不是挑过了?");
	return 0;
	}
	if(str=="张乘风")
        {
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就拜我的首徒张乘风吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="张乘云")
	{
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒张乘云吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="范松")
	{
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子范松吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="赵鹤")
	{
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子赵鹤吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="梁发")
	{
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的五弟子梁发吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="何双双")
	{
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何双双吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="李逍遥")
	{
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遥吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	command("say 没这人!");
	return 0;
	}
