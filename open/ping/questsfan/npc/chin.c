//by dhk 2000.5.23
#include "/open/open.h"
#include <ansi.h>
inherit F_VENDOR;

void create()
{
        set_name("秦厉害",({"vendor chin","vendor","chin"}));
        set("title",""HIR"火龙神探"NOR"");
        set("gender", "男性" );
        set("age", 27);
set("long", @LONG
四处设摊卖些不知道〔真的〕还是〔假的〕的情报的人,你可以列出(list)他卖些什么...
LONG
        );
        set("combat_exp",800);
        set("no_fight",1);
        set("no_kill",1);
        set("attitude", "friendly");
        set_skill("dodge", 25);
        set_skill("hammer", 17);
        set_skill("parry", 27);
        set("vendor_goods", ({
                "/open/ping/questsfan/obj/paper1",
        }) );
        setup();
        add_money("gold",135);
}

void greeting(object ob)
{
        int gender,per;
        gender = 0;
        per = ob->query("per");
        if( !ob || environment(ob) != environment() ) return;
        if( ob->query("gender") == "女性")
          gender = 1;
        switch( random(3) ) {
                case 0:
                if( per < 18 && gender)
                  say("秦厉害靠近你小声的说: 唉! "+ob->name(1)
                       +",也许妳该去一下媚登峰!\n");

                say("秦厉害靠近你小声的说: 这位"+RANK_D->query_respect(ob)
                        +"其实我是狂想情报总经销!\n");
                        break;
                case 1:
                if( per > 22 )
                   say("秦厉害嘶声么\喝道: "+ob->name(1)
                        +"长的好像电影明星喔!\n");

                say("秦厉害嘶声么\喝道: "+RANK_D->query_respect(ob)
                    +",我知道好多神秘的内幕呦!! 要买吗!?\n");
                        break;
                case 2:
                if( per < 15)
        say("秦厉害小声的说: "+ob->name(1)+",请具备一点公德心好吗? 人长的"
                    +"丑就不要上街吓人.\n");
                if( per > 26 && gender)
                    say("秦厉害赞叹道: 哇! 大美女"+ob->name(1)
                        +",妳可真是天仙下凡呀!!\n");

                say("秦厉害高声喊道: 端午节大优待,"+RANK_D->query_respect(ob)
                        +"要的话，我可以算便宜一点喔!一份1000 gold!!!\n");
                        break;
         }

}

void init()
{ 
  ::init();
  add_action("do_nod","nod");
  remove_call_out("check_tensanmark");
  call_out("check_tensanmark",1,this_player()); 
}

void check_tensanmark(object me)
{
  if(present("tensan mark",me))
  {
    command("say 这不是天山通行令吗？我早就想进天山看看但一直不得其门而入。");
    command("hmm");
    command("say 我用高价向你收购，你愿意割爱卖给我吗？");
    me->set_temp("tensan/wait_answer",1);
  }
}

int do_nod()
{
  object me,ob,money;
  me = this_player();
  ob = present("tensan mark",me);
  money=new("/obj/money/diamond");
  money->set_amount(1+random(3));
  if(me->query_temp("tensan/wait_answer")==1)
  {
    command("say 太好了！那就银货两契不得反悔，拿去吧！这是你应得的。");   
    destruct(ob);
    money->move(me);
    me->delete_temp("tensan/wait_answer",1);
  }
  return 0;
}
    
