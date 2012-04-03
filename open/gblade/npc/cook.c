inherit NPC;
string do_lend();
int i=1;

string do_ask (object me);

void create()
{
	set_name("老刘", ({ "cook liu","liu" }) );
        set("long", "
他是金刀门特地从京城请来的厨师，手艺一流；看他那短小的手指，实在
很难想像能做出什么精致的菜肴。
");
        
        set("age", 35);
	set("combat_exp", 500);
	set_skill("blade", 34);
        set_skill("dodge", 30);
        set_skill("parry", 32);
	set("title","厨师");
        

        set("race", "人类");
        set( "gender", "男性");


        set("limbs", ({ "头部","胸部"  "双手", "双脚", "背部" ,"肥大的肚子","腰部"}) );
     
        set("attitude", "friend");

	set("chat_chance",5);
        set("chat_msg", ({"你想知道怎么样做好吃菜吗？\n",
        }) );
        set("chat_chance_combat",30);
set("chat_msg_combat",({"打我一个不会武功的厨师，算得上什么英雄好汉。\n"
        }));
	set("inquiry",([
	"捕虫网" : "嗯 ,常常有些丫头来向我借捕虫网 !\n",
	"丫头" : "就是金刀门内那些丫鬟嘛 ! 真是一个比一个爱玩 !\n",
	"巧儿" : "嗯 , 她是大小姐的贴身丫鬟 , 想接近大小姐 , 非得从她下手 !\n",
	"借捕虫网" : (:do_lend:)
	]));
        setup();
	 carry_object("/open/gblade/obj/knife.c")->wield();
	add_money("silver",10);
}

string do_lend()
{
	if(this_player()->query_temp("net"))
	return "你还没还我耶 !";
	if(i==0)
	return "已经借给别人啰 !";
	new("/open/gblade/obj/net")->move(this_player());
	message_vision("老刘取出了捕虫网 , 交给$N \n",this_player());
	i=i-1;
	this_player()->set_temp("net",1);
	return "用完了可要还我喔 !";
}
int accept_object(object who, object ob)
{
	if(ob->query("id")=="net")
	{
	command("smile");
	if(!this_player()->query("quests/lotch") && this_player()->query("lotch")<1 && present("papyrus",this_player() ) )
	{
	command("say 看你是个正人君子 , 我告诉你个消息 !");
	command("say 王家大小姐可是上通天文 , 下知地理 , 有何疑难 , 找她就对啦 !");
	this_player()->set_temp("know_leing",1);
	}
	this_player()->delete_temp("net");
	destruct(ob);
	i=i+1;
	return 1;
	}
return 1;
}
