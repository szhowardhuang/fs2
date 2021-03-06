// dusa.c by oda

#include </open/open.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string do_ask();
string do_ask2();

void create()
{
        set_name("杜杀", ({ "du sa", "du", "sa" }) );
        set("nickname", "血手");
        set("title", "恶人谷大头目");
        set("gender", "男性");
        set("age", 41);
        set("class", "bandit");
        set("guild_master", 1);
        set("bellicosity", 2500);
        set("attitude", "badman");
        set("combat_exp", 3000000);
        set("long","这个人身子又瘦又长，一身雪白的长袍，他的脸就跟他的衣服一样苍白。
仔细一看，你才发现他的左手已经断了，并且装上了一个锋利的钢钩。他就是恶人谷中
最令人畏惧的十大恶人之首－「血手”杜杀。");

        set("str", 40);
        set("cor", 40);
        set("int", 24);
        set("spi", 22);
        set("cps", 30);
        set("con", 30);
        set("per", 16);
        set("max_gin", 10000);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("gin", 10000);
        set("kee", 10000);
        set("sen", 10000);
        set("max_force",5000);
        set("force",5000);
        set("force_factor", 10);

        set_skill("array",80);
        set_skill("magic",20);
        set_skill("spells",20);
        set_skill("bad-array",100);
        set_skill("change",100);
        set_skill("dodge", 80);
        set_skill("sword",80);
        set_skill("ghost-steps",100);
        set_skill("force", 70);
        set_skill("badforce",100);
    set_skill("counter",80);
        set_skill("move", 80);
        set_skill("parry",70);
        set_skill("unarmed",80);
        set_skill("cure",50);
        set_skill("badstrike",100);
        set_skill("gamble", 50);
        set_skill("literate",30);
        map_skill("unarmed", "badstrike");
        map_skill("array", "bad-array");
        map_skill("parry", "badstrike");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        map_skill("move", "ghost-steps");
        set("quests/badroar",1);
        set("functions/evil-blade/level",100);
        set("functions/badroar/level",50);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.evil-blade" :),
        (: perform_action, "unarmed.badroar" :),
        }) );
        set("inquiry",([
        "左手" : (: do_ask :),
        "恶人森林" : (: do_ask2 :),
        ]));

        setup();
        create_family("恶人谷",1,"大头目");
        set("family/next_title", "小喽喽");
        add_money("gold", 10);
        carry_object(BAD_OBJ"badhelmet")->wear();
        carry_object(BAD_OBJ"evil_claw.c")->wield();
}

void init()
{
        add_action("do_join", "join");
}

int accept_fight(object who)
{
        message_vision("杜杀冷冷的瞄了$N一眼。\n", who);
        command("say 哼，不自量力的家伙。\n");
        return 1;
}

void attempt_apprentice(object who)
{
        if( !who->query("class") ) {
                command("shake "+who->query("id"));
                command("say 等你加入(join)盗贼这一行再说吧。");
                return;
        }
        if( who->query("class")!="bandit" ) {
                command("stare "+who->query("id"));
                command("say 恶人谷是干强盗的，你们这些善良老百姓还是快滚吧！");
                return;
        }
        if(!who->query("quests/badman_license")) {
                tell_object(who,"杜杀冷冷的看着你说：就凭你也想加入恶人谷？等你除掉燕南天这家伙再说吧！\n");
                who->delete_temp("pending/apprentice");
                return;
        }
        command("look "+who->query("id"));
        command("say 好！我就收你这个徒弟。");
        command("recruit "+who->query("id"));
        tell_object(who,"杜杀说道：记住，恶人谷认证不认人，要是恶人证遗失的话就再去找你师兄司马烟拿。\n");
        command("say 不过既然你加入了恶人谷，就永远别想脱离这里，否则....");
        command("hehe "+who->query("id"));
    if (who->query("quests/badroar",1))
    {
       tell_object(who,"嗯 ,底子不错嘛 !好 ,你可以不用从基层干起!!!\n");
       who->set("title","[33m大[31m坏[32m蛋[0m");
       return;
    }
}

int do_join()
{
        object who;
        who = this_player();

    if( who->query("class"))
    return notify_fail("要加入工会就去找老大点头!\n");

   return 1;

/*
        if( who->query("class") )
                return notify_fail("你已经加入其他工会了。\n");
        who->set("class", "bandit");
        message("system", HIW"杜杀仰天狂啸：咱们盗贼又多了一个极恶之徒－"HIR+who->query("name")+HIW"\n大家要小心啦！哈哈哈哈！\n"NOR, users());

        return 1;
*/
}


void die()
{
/*
        object weapon;
        weapon = present("hook", this_object());
        destruct(weapon);
*/
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
          new("/open/sky/obj2/soil_stone")->move(environment(winner));
          message_vision(HIM"\n从杜杀的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/soil_stone",sprintf("%s(%s) 让杜杀掉下了地尊石于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }else{
        j=random(12000);
          if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
          {      
          new("/open/sky/obj2/soil_stone")->move(environment(winner));
          message_vision(HIM"\n从杜杀的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/soil_stone",sprintf("%s(%s) 让杜杀掉下了地尊石于 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
          }
        }
        tell_object(users(),"
"RED"恶人谷"HIY"传来撕天裂地的怒吼：\n
                   "HIY"「"HIR"天魔双刀血立溅，混杀一吼魂飞灭！"HIY"”\n
                　唉～～想我「"HIR"血手"HIY"”"HIG"杜杀"HIY"闯荡江湖三十余年...\n
                         一生所杀之人已不可计数...\n
                  而今日却失手命葬于"HIW+winner->query("family/family_name")+HIY"小贼－"+HIC+winner->query("name")+HIY+"之手...\n
                     "RED"一世恶名"HIY"如今毁于一旦，真是可恨啊！\n"NOR);
        ::die();
}

int accept_object(object me,object ob)
{
  if(ob->query("id")=="sa`s hand")
   {
     if(me->query("quests/badroar"))
      {
       command("say 我不是传你混杀吼了吗 ?还想要谢礼啊 !");
        destruct(ob);
       return 1;
      }
    if(me->query("class")!="bandit")
    {
        kill_ob(this_player());
        destruct(ob);
        command("say 你不咱恶人谷的 ,怎么能到森林去找我的左手!?");
    }
   if (me->query_temp("marks/allow")!=1)
    {
     destruct(ob);
     command("say 喔,谢啦!不过下次别再随便乱跑禁区!!!");
    }
  else {
  command("nod "+me->query("id"));
  me->set("quests/badroar",1);
  destruct(ob);
command("say 不愧\是咱们恶人谷的模范 !这样吧 ,我也没什么好东西能给你 ,便传你\n我们恶人在外行走江湖的口诀--穷凶恶极 ,神哭鬼嚎....就这样 ,\n我俩以后可互不相欠！");
  tell_object(me,"你稍微领悟了这八字的意义 ,心中杀气一聚 ,混杀吼(badroar)的功力增加了!!\n");
  me->set("title","[33m大[31m坏[32m蛋[0m");
        }
  return 1;
    }
}
string do_ask()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
  if(who->query_temp("marks/hand_again")!=1)
  {
   who->set_temp("marks/hand",1);
   return "你这个混蛋 !区区一个小啰喽还敢管本大爷闲事 !还不快滚 ?\n";
  }
  else
  {
   who->set_temp("marks/allow",1);
    return "没想到你的意志这么坚定 .好吧 ,就告诉你 .我的左手是当初我们恶人谷众多恶人将燕南天引诱到恶人森林时 ,不小心被燕南天给砍断的 .只是没想到他却被你这么一个小伙子给杀了....对了 !既然你能将燕南天给杀了 ,那找回我那只断手应该也不是难事吧 ?至于在哪里嘛....你就去问问那个只会做药的老头子吧 .\n";
  }
  }
  else
  {
   return "你不是拿回来了..?还想干嘛..?\n";
  }
}
string do_ask2()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
    return "一个小啰喽还想到森林去 ?送死啊!?\n";
  }
  else
  {
    who->set_temp("marks/allow",1);
    return "想去森林 ?好 ,没问题 !去跟轩辕三光那赌鬼说吧 !\n";
  }
}

