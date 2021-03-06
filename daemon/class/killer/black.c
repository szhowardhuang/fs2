//blackman.c by urd
//87.8.19  为了当成谜题，所以又被我修改了
//87.9.30  再次因为解谜上的需要，又被修改一次
//87.10.11 因为nod的问题，在修正一次程式
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string ask_card();
string ask_dark();
string ask_ghostcard();
void create()
{
	set_name("黑衣人",({"black suit","suit"}));
	set("long","这是杀手跟忍者工会的长老 ,原本负责在京城中接收新会员 .\n
	                  目前因为各大门派的逼迫，不得以只好退到杀手总坛的后山.\n
		      他目前身兼黑巾杀手的灵异掌令，地位非常崇高。\n
		      他跟（叶孤城）之间似乎有不少牵扯。\n");
	set("gender","男性");
	set("class","killer");
	set("nickname","天地无用");
	set("combat_exp",1000000);
	set("attitude","heroism");
	set("age",43);
	set("title","天灵老人");
set("guild_master",1);
	set("str", 44);
	set("cor", 24);
	set("cps", 18);
	set("per", 24);
	set("int", 42);
	set("force",1400);
	set_skill("literate",40);
	set("max_force",1400);
	set("max_kee",2000);
	set_skill("magic",50);
	set_skill("array",50);
	set_skill("move",60);
	set_skill("force",60);
	set_skill("dodge",80);
	set_skill("parry",60);
	set_skill("spells",50);
	set_skill("sword",50);
	set_skill("unarmed",50);
	set_skill("blade",50);
	set_skill("staff",50);
	set_skill("throwing",70);
	set_skill("dagger",55);
	set("force_factor",10);
	set_skill("hammer",50);
set("inquiry",([
"叶孤城" :"他是我最要好的朋友与最佳的对手，但是因为（小如）那一件事........\n",
"小如" :"她就是叶玲如，当年的杀手第一美女，引起我与叶孤城互相(争夺)\n",
"争夺":"这是一件惨事，你愿意点头答应我一件事吗？？\n",
"杀手密令" : (: ask_card :),
"灵异令牌" : (: ask_ghostcard :),
"特殊身法" : (: ask_dark :),
]));

setup();
carry_object("/open/killer/memory/hair.c");
carry_object("/obj/cloth")->wear();
add_money("gold",10);
}

void init()
{
	add_action("do_join","join");
	add_action("do_nod","nod");
    add_action("do_show","show_card");
}

int accept_object(object wo,object ob)
{
  object me,ob2,obj;  
  me=this_player();

  if(ob->query("id") == "sword_head")
  {  //第三进阶用的谜
	if( me->query_temp("head") !=4 ) 
	{
		command("say 连七子的人头没有办法自己拿，没资格出这个任务！");
		me->delete_temp("head");
		return 0;
	}
	//表有人头，而且人头是自己拿的
	command("nod");
	obj = new("/open/killer/headkill/obj/ghost_card");
	obj->move(this_player());
	message_vision("$N给$n一支"+obj->name()+"\n",this_object(),this_player());
	me->set_temp("head",5);
  }
  if(ob->query("id") == "card")  //进行到给杀手密令的地方     
  {  //第二进阶用的谜
    if (this_player()->query_temp("memory") != 9)
    {
	command("say 给我这个干嘛！，别人帮你拿的吧？");
      	return 0;
    }
    command("say 果然是孤城密令！！干的好，小鬼！看来我们杀手后继有人了！！");
    command("say  就让我给你杀手密令吧！！");
    message_vision(HIR"渡永天交给$N一面杀手密令\n"NOR,me);	
    ob2=new("/open/killer/memory/killer_card.c");
    ob2->move(me);
    command("say  这是证明杀手有资格在各组任职的密令，不见了记得回来找我要( 杀手密令）");
    command("say  只要小渡把任职系统做好，你就可以任职于各组织间");
    command("say   现在就让我帮你把魔气杀的限制打开到第二层，让你可以在将限制提高50级");
    message_vision(HIR"渡永天迅速在$N身上拍打\n"NOR,me);	
    tell_object(me,"你感到体内一阵真气运行，看来魔气杀可以发挥更强大的威力了\n");
   message("system",HIW "渡永天纵声大呼 :\n
		" +this_player()->name()+"你已经可以把魔气杀变的更强大了!!\n\n"NOR,users());
    me->set("title",HIM"新生代特级杀手"NOR);
    me->set_temp("memory",0);
    me->set("quest/memory",1);
    return 1;
  }
 destruct(ob);
 return 0;
}

int do_join()
{
	if(this_player()->query("class"))
		return notify_fail("你已经加入其他工会了。\n");
	this_player()->set("class","avatar");
	message("system",HIW "黑衣人纵声大呼 :\n
		欢迎" +this_player()->name()+"加入工会!!\n\n"NOR,users());
	return 1;
}

int do_nod()
{ //因为nod是emote，所以如果用notify_fail()去回应的话
  //因为，这object在房间物件中的一个
  //所以，遇到noitfy_fail，会去搜寻在这里符合的COMMAND
  //因为，会符合房间的emote动作，所以notify会忽略目前的nod
  //而去当成是房间的emote，因此变成此段成是无效化
  object me=this_player();

  if (me->query("class")  != "killer")
  {
        message_vision(HIY"罢了....你这种外人没资格知道，杀手自己的事情。\n"NOR,me);
	return 1;
  }
  if (me->query("quest/rain") != 1)
  {
  	message_vision(HIY"孩子，你还小，等你成长到够资格后，再帮我吧。\n"NOR,me);
	return 1;
  }
  if (me->query("quest/memory") == 1)
  {
  	message_vision(HIY"你不是知道了吗？\n"NOR,me);
	return 1;
  }
  if (this_player()->query_temp("memroy") == 1)
  {
  	message_vision(HIY"乖儿子你想点几次头呀\n"NOR,me);
	return 1;
  }
  me->set_temp("memory",1);
  new("/open/killer/memory/hair.c")->move(me);
  command("say 你帮我把这一个发箍，交给叶玲如好吗？");
  return 1;
}

int do_show()
{
  if ( !present("card",this_player()) )
	return notify_fail("秀？你要跳脱衣舞呀？.....我可没兴趣看呀.........\n");
  if (this_player()->query_temp("memory") != 8)
	return notify_fail("你从哪里偷来的令牌？快滚！！\n");
  this_player()->set_temp("memory",9);
	message_vision(HIY"孤城密令？是玲如他给你的？快把他交给我看看!!"NOR,this_player());
  return 1;
}

string ask_ghostcard()
{
 	object ob;
    object me=this_player();

if (me->query_temp("head") != 2)
	return "你说什么？老人家有重听，没听到耶。。。";
//ob = new("/open/killer/headkill/obj/ghost_card.c");
//ob->move(this_player());
message_vision("想要灵异令牌？去把仙剑七子中任何一个人的人头提来见我！\n",me);
message_vision("要灵异令牌就是要削减其他门派的势力，所以先证明你的能力吧\n",me);
me->set_temp("head",3);
return "人头给我，我就给你令牌";
}

string ask_card()
{
 	object ob;
	if( present("killer_card",this_player()) ) return "想要甚么 ?";
if( !this_player()->query("quest/memory") ) return "想要甚么 ?";
ob = new("/data/autoload/killer/killer_card.c");
ob->move(this_player());
message_vision("$N给$一张杀手密令。\n",this_object(),this_player());
return "小心不要再弄掉了";
}

string ask_dark()
{
	object me=this_player();
	
if( me->query_temp("firstpart") != 4) return "你没资格知道......";
tell_object(me,HIY"
‘ 我也不是很清楚，但是传说中，这一个身法是柴荣由庄敬柔的身上学到的 \n
   但是有另外一说此一身法是飘花宫的特殊技巧，名为--分功化影身法。
   但是，这一个说法并没有得到柴荣的证明，传说似乎只是传说\n
   因为就连当年的背叛事件，我也没看到柴荣使出此一身法。\n
   更何况，我也没看过魔教徒去使出此一身法......\n
   或许你去找柴荣问(特殊身法)看看吧？你应该还记的他躲在哪里吧？’ \n
\n"NOR);
me->set_temp("firstpart",5);
return "到那里search看看吧";
}

