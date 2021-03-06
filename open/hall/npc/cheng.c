inherit NPC;
#include <ansi.h>
#include <combat.h>
#include </open/open.h>
string do_thief();
string ask_test();
void create()
{
	set_name("纪无尘", ({ "chi wu-cheng","chi", "cheng" }) );
	set("title", "总理执事");
  //set("nickname", "[1;34m□[36m□[34m□[36m□[34m□[36m□[34m□[36m□[0m NOR");
	set("class","officer");
	set("gender", "男性" );
	set_max_encumbrance(1000000);
	set("age", 46);
	set("str", 20);
	set("cor", 20);
	set("cps", 20);
	set("int", 30);
	set("spi", 20);
	set("kar", 26);
	set("per", 20);
	set("con", 30);

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 5);

	set("long", @LONG
    人称‘京城之光’，人说其断案如神，决不徇私茍且。所以这里的
百姓都很敬爱他。也因为他的功绩辉煌，先皇特赐其一柄尚方宝剑，准
其将恶惯满盈之人，先斩后奏!!
LONG);

	set("combat_exp",500000);
	set("score", 30000);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	"无尘大人喝道：大胆狂徒!!  拿下!!\n",
	"无尘大人喝道：公堂之上竟敢撒野!!  给我严惩!!\n"
	}) );

	set_skill("unarmed", 30);
	set_skill("force",  20);
	set_skill("parry",  20);
	set_skill("dodge",  20);
	set_skill("sword",  20);
	set_skill("literate", 90);

	set("inquiry", ([
	  "机器人" : "哼!! 谁被我抓到是机器人的话，斩立决!!",
       "试炼印记" : (:ask_test:),
	  "accuse" : "想缉捕机器人的话，请先到门口击鼓申冤(accuse)。",
	  "thief"  : (: do_thief :),
	  "测试"   : "想抓贼(thief)就得先经过我测试, 若能连接我五招便算过关了。",
	  "test"   : "想抓贼(thief)就得先经过我测试, 若能连接我五招便算过关了。",
	  "accept" : "要接受测试吗? 那就打(accept test)。",
	]) );

	setup();
	carry_object(HALL_NPC"obj/god_sword")->wield();
	carry_object(HALL_NPC"obj/o_cloth")->wear();
}

string do_thief()
{
	object me=this_player();
    if( me->query("quests/catch_thief") == 0 || (me->query("marks/ask_linpo") && me->query("family/family_name")=="段家"))
	{
	  if( me->query_temp("thief") == 0 )
	    me->set_temp("thief",1);
	  return (RANK_D->query_respect(me)+"是有意帮忙抓京城大盗的吗? "+
		"只是最近有许多没本事的人前来应征\n, "+RANK_D->query_respect(me)+
		"若有本事的话请先接受测试吧(accept test)。");
	}
	else
	{
	  command("smile");
	  command("pat "+me->query("id"));
	  return ("这件事真是多亏了你, 如今京城又恢复平静了。");
	}
}					    
void init()
{
	add_action("do_accept","accept");
}
int do_accept(string str)
{
	int i;
	object ob=this_object();
	object me=this_player();
	object mark=new(CAPITAL_OBJ"mark");
	if( me->query_temp("thief") == 0)
	  command("say 先问问为何要测试吧。");
	if( me->query_temp("thief") > 1)
	  command("say 不是测试过了吗?");
	if( me->query_temp("thief") == 1)
	{
	if( str=="test")
	{
	  command("say 好! 待老夫来试试你! 小心了");
	  for(i=0;i<5;i++)
	    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);
	  if( me->query("kee") > 1 )
	  {
	    command("say 果然不愧\为真英雄, 那我就将这件事原原本本的说与你听了");
	    command("thank "+me->query("id"));
	    command("say 这京城大盗目前为止已得手不下数次, 连京城首富干通天的宅第也\n"+
	    "		 遭殃了, 因此这才惊动皇上下令一个月之内必须破案, 既然"+RANK_D->query_respect(me)+
	    "\n 	   自告奋勇, 那这件事就拜托你了。将此名大盗逮捕归案, 则必定重重有赏。");
	    message_vision("$N交给$n一面「衙门令牌”。\n",ob,me);
	    mark->move(me);
	    command("say 希望这面令牌对你办案能有所助益。");
	    me->set_temp("thief",2);
	  }
	  else
	  {
	    command("say 罢了罢了, 我还是继续等真英雄来吧");
	    command("sigh");
	  }
	}  
	else
	  write("接受什么?!\n");
	}
	return 1;		 
}

int accept_object(object me, object man)
{
	string target = "赵琴风";
	object ob=this_object();
	object reward;
	if( me->query_temp("thief") < 2 )
	  return notify_fail(ob->query("name")+"说道：疑..我好像没有托你办这件事嘛。既然你这么热心, 那就谢啰。\n");
	if( man->query("victim_name") == target || man->query("name") == target )
	{
	  command("say 真是太好了, 我托付你的事终于顺利的达成了。");
	  if( man->query("name") == target )
	  {
	    command("say 按照约定, 这就是你应得的赏金。\n");
	    reward = new("/obj/money/gold");
	    reward->set_amount(5);
	    reward->move(me);
	    message_vision("$N赐给$n五两黄金。\n",ob,me);
	  }
	  else
	  {
	    command("say 可惜这京城大盗已死, 因此赏金只有一半了。");
	    reward = new("/obj/money/gold");
	    reward->set_amount(2);
	    reward->move(me);
	    message_vision("$N赐给$n二两黄金。\n",ob,me);
	  }
	  if( !me->query("quests/catch_thief") )
	  {
	    write("\n\n[1;36m**完成京城大盗之谜***[0m\n你得到实战经验 200。\n");
	    me->add("combat_exp",200);
	    if( me->query("class") == "officer" )
	    {
	      write("你得到政治权力 20。\n");
	      me->add("max_officer_power",20);
	    }  
	    me->set("quests/catch_thief",1);
	    me->delete_temp("thief");
	  }
	  destruct(man);
	}
	return 1;
}	
	
void die()
{    
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner)
	{
	::die();
	return ;
        }

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj9/health_charm")->move(environment(winner));
	  message_vision(HIM"\n从纪无尘的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/health_charm",sprintf("%s(%s) 让纪无尘掉下了健康之符于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/health_charm")->move(environment(winner));
	  message_vision(HIM"\n从纪无尘的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/health_charm",sprintf("%s(%s) 让纪无尘掉下了健康之符于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}
string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
 if(this_player()->query("quests/catch_thief",1)&&this_player()->query("quests/yantestmark1",1)  && this_player()->query("quests/2ndtest",2))
  {
  int i;
  i=6+random(5);
  command("say 谢谢您的帮忙.我愿意将appo给我的印记传到你身上!\n");
  tell_object(this_player(),HIW"瞬间由纪无尘将手搭在你的肩上..你顿时觉得一股暖意由纪无尘的手中传过来\n"NOR);
  this_player()->set("quests/2ndtest",i);
  this_player()->set("quests/yantestmark2",1);
  return("最后一个印记在圣贤书手上,你可以去找他问问了\n");
  }
 else if (this_player()->query("quests/yantestmark2")>1)
  return ("我已经把印记给你了..你还要做什么\n");
 else
  return ("去当我把京城大盗找出来我就跟你说印记在哪。\n");
 }
else
 return ("啥印记..你在说什么?\n");
}
