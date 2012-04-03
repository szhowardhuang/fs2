//展伯承 make by wugi
inherit NPC;
string ask_test();
void create()
{
	set_name("展伯承",({"bo chen","bo","chen"}));
	set("gender","男性");
	set("age",25);
	set("class","blademan");
	set("str",25);
        set("long","金刀弟子 ,看他神色慌张 ,不知在(找寻)什么东西 ?\n");
	set("combat_exp",20000);
	set_skill("blade",40);
	set_skill("parry",40);
	set_skill("dodge",40);
	set_skill("gold-blade",50);
	set_skill("fly-steps",50);
	set_skill("sixforce",40);
	map_skill("blade","gold-blade");
	map_skill("dodge","fly-steps");
	map_skill("move","fly-steps");
	map_skill("parry","gold-blade");
	map_skill("force","sixforce");
	set("chat_chance",10);
	set("chat_msg",({
		"展伯承到处看来看去 ,神色甚是慌张.\n",
		"展伯承说道 : 完蛋啦 ,怎么向师父交代呢 ?\n"
		}));
	set("inquiry",([
	"找寻" : "师父命我送幅(名画)给仙剑郑掌门贺寿 ,昨天在(投宿)时 ,却被偷了 .\n",
    "试炼印记" : (:ask_test:),
	"名画" : "那是北宋范宽的名作啊 !\n",
	"投宿" : "我是住在蜀中城东的一家客栈 ,唉 , 都怪我不小心 .\n",
	]));
	setup();
	create_family("金刀门",6,"弟子");
	carry_object("/open/gblade/obj/blade1")->wield();
	add_money("gold",10);
}



int accept_fight(object who)
{
return notify_fail("展伯承说道 : 你没看到我很忙吗。\n");
}


int accept_object(object me,object ob)
{
  if(ob->query("id")=="picture")
   {
	if(me->query("quests/bochen_trouble"))
      {
       command("say 上次真多谢你的帮忙 !");
       return 1;
      }
    if(me->query("family/family_name")!="金刀门")
    {
      command("thank "+me->query("id"));
      me->set("quests/bochen_trouble",1);
      new("/obj/money/gold")->move(me);
      me->add("combat_exp",100);
      message_vision("展伯承取出一锭黄金 ,交给$N !\n",me);
      command("say 小小黄金 ,不成敬意 ,以后金刀门永当你是客!");
    }
 else {
	command("smile "+me->query("id"));
	if(me->query("gender")=="男性")
	command("say 小师弟 ,不简单喔 !");
	if(me->query("gender")=="女性")
        command("say 小师妹 ,真是女中豪杰 !");
	me->set("quests/bochen_trouble",1);
	new("/obj/money/gold")->move(me);
	me->add("combat_exp",500);
	message_vision("展伯承取出一锭黄金 ,交给$N !\n",me);
	command("say 为了报答你 ,师兄教你几手 !");
	tell_object(me,"听了展伯承的教导 ,你觉的自己似忽进步了不少 !\n");
	}
  return 1;
    }
}
string ask_test()
{
if(this_player()->query("quests/yan")==3)
{
 if(this_player()->query("quests/bochen_trouble",1)&&this_player()->query("quests/2ndtest")<1)
{
int i;
i=random(3)+1;
command("say 谢谢你之前的帮忙.我愿意将我我手上的试炼印记传到你身上!\n");
this_player()->set("quests/2ndtest",i);
this_player()->set("quests/yantestmark1",1);
return("不过..剩下的印记..你就要寻遍整个狂想大陆.但是我可以瞒着appo 偷偷跟你说.其实..他都把印记藏在狂想quest人物的身上..你可以打(quest)看看有哪些地方比较有可能\n");
}
 else if (this_player()->query("quests/2ndtest")!=0)
  return ("我已经把印记给你了..你还要做什么\n");
 else
return ("装校维..你都不知道我的烦恼..还想要印记!!\n");
}
else 
return ("啥印记..你在说什么?\n");
}
