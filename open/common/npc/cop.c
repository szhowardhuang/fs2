#include <ansi.h>

#include <login.h>
inherit NPC;

string do_ask (object me);
int random_move();

void create()
{
        seteuid (geteuid());
        set_name("九省总巡捕--林凌", ({ "cop head", "cop", "head" }) );
	set("nickname", "铁锁横江");
        set("long", @LONG
眼前这位是江湖中人人闻名色变的九省总巡捕，他外号铁锁横江
的由来可不是九省总巡捕逮捕杀人犯就好像驾船碰到铁锁横江般地碍
手碍脚，而是所有江洋大盗一被九省总巡捕盯上，从此生活就有如铁
锁横江，永远也不得安宁。
    如果你有意向他挑战，那你可得小心他对你采取极严厉的报负手
段。三十五年前他为了追捕汪洋大盗--滑不溜手--胡一刀曾经连续八
天八夜不睡，躲在船底的夹层里，他的狠与毅力是跟他的外号相配合
的。如果你想知道有谁是他最想追捕的江洋大盗, 可以问他有关杀手
(killer)的事。
    你看到总捕头口袋里装了不少金牌，难道那就是有名的 PK 执照
(pk license)吗? 也许你可以跟他申请(apply) 一张来保身哦!
LONG
	);

	set( "age", 55);

        set("max_gin", 5000);
        set("max_kee", 5000);
        set("max_sen", 5000);
        set("max_atman", 9999);
        set("atman", 9999);
        set("max_force", 5000);
        set("force", 5000);
        set("max_mana", 5000);
        set("mana", 5000);

        set("str", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
        set("int", 100);
        set("con", 100);

	set( "force_factor", 3 );
        set("combat_exp", 5000000);
        set_skill("staff", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

	// 技能
	//		1.怪物学过的技能: set_skill( "技巧名", 数值 );
	//		2.怪物施展的技能: map_skill( "技巧种类", "技巧名" );
	// set_skill("celestial", 10);
	// map_skill("force", "celestial");

	set("race", "人类");

	set( "gender", "男性");

        set("limbs", ({ "头部", "身体", "右脚", "左脚", "前胸", "后背" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("random_move",-1);
	set("chat_msg_combat", ({
	    CYN "九省总巡捕说道: 弃暗投明吧?!\n" NOR,
	    CYN "九省总巡捕说道: 你现在所说的一切, 将作为呈堂证供。\n" NOR,
	    CYN "九省总巡捕说道: 人吃五谷杂粮, 谁能无过?!\n" NOR,
	    CYN "九省总巡捕说道: 放下屠刀, 立地成佛, 乖乖受死吧。\n" NOR,
	}) );

	set("inquiry", ([
	    "killer"	:	(: do_ask :),
	    "杀手"	:	(: do_ask :),
	]) );

        set("chat_chance", 6);
        set("chat_msg", ({
	    CYN "九省总巡捕说道: 我生平最恨杀人放火的事了。\n" NOR,
	    CYN "九省总巡捕说道: 唉, 为了追捕汪洋大盗，害我杀孽颇重。\n" NOR,
	    CYN "九省总巡捕说道: 我不入地狱谁入地狱?\n" NOR,
	    CYN "九省总巡捕说道: 偶而做做坏事也就罢了, 别杀人喔。\n" NOR,
	    CYN "九省总巡捕说道: 别以为九省巡捕是叫假的。\n" NOR,
	    CYN "九省总巡捕说道: 你知道铁锁横江的真义吗?\n" NOR,
        }) );

        set_temp("apply/armor", 2);

        setup();
}

int random_move ()
{
  tell_room (environment(this_object()),
             CYN "九省总巡捕说道: 我走了...\n" NOR);
  ::random_move();
}

// 当有其他生物对这个人物下 kill 指令的时候，会呼叫这个附加函数
int accept_kill(object who)
{
  object	me;
  string	pker;

  me = this_object();
  pker = who->query("id");

  // 有 PK 执照就不被追杀....
  if (present ("pk license", who)) {
    say("九省总巡捕说道: 既然阁下喜欢杀人, 在下只好奉陪。\n");
    ::accept_kill(who);
    return 1;
  }

  if (!wizardp(who)) {	// 想打九省总巡捕? 不要命了吗?
    if ( !PK_D->get_pk_time ( pker ) ) {
      if (PK_D->add_pker (pker, time()))
        message("system",
                CYN"九省总巡捕大声叫道: "+who->short()+
                "竟敢公然侮辱法律向我挑战!!\n"+
                "九省总巡捕大声叫道: 我以铁锁横江的的名号保证,"+
	        " 不抓他归案誓不成佛!!\n"NOR,
                users()
        );
    }
    else {
      message("system",
              CYN"九省总巡捕大声叫道: "+who->short()+
              "这江洋大盗碰到我不敢快逃走, 还敢找我单挑!!\n"+
              "九省总巡捕大声叫道: 我以铁锁横江的的名号保证,"+
              " 不抓他归案誓不成佛!!\n"NOR,
              users()
      );

    }
  }
  return 1;
}

// 当有人用 give 指令给这个非玩家人物东西时，会呼叫这个附加函数
int accept_object(object who, object item)
{
  string	pker;

  if (item->query("id") == "pk license") {
    destruct (item);
    tell_object (who, "九省总捕头告诉你: 好孩子, 想做个安份良民了啊!!\n"+
		      "总补头想了想, 说道: 好吧, 我帮你保管 PK 执照。\n");
  }
  else
    tell_object (who, 
      CYN "九省总巡捕告诉你: 你想贿赂我? 难不成你把我看成贪官污吏?!\n" NOR);

  return 1;
}

// 当这名人物杀死一个敌人的时候会呼叫这个附加函数
void killed_enemy(object who)
{
  if ( PK_D->delete_pker (who->query("id")) ) 
    shout (CYN"九省总巡捕大声叫道: 逮捕江洋大盗"+who->name()+"("+
           who->query("id")+")一名。\n");
}

string do_ask (object me)
{
  string	pkers, *pklist;
  int		i;

  pklist = PK_D->query_pk_list();
  if (sizeof (pklist)) {
    pkers = "\n";
    for (i=1; i<=sizeof (pklist); i++)
      pkers += i+" "+pklist[i-1]+"\n";
    return pkers;
  }
  else return CYN "最近江湖虽然风起云涌, 但是海内绥平, 国境平安。\n" NOR;
}

void init ()
{
  object	ob;

  ::init();

  // 这一段利用 init 配合 call_out 来每一次心跳都检查是否有人跑过来..
  // 注意, remove_call_out 是为了减少 bug....尤其对那种久久 call_out 
  // 一次的来说更重要, 例如 拍卖, 流血中毒等.....
  if ( interactive (ob=this_player()) && !is_fighting(ob)) {
    remove_call_out ("greeting");
    call_out ("greeting", 1, ob);
  }
  add_action ("do_apply", "apply");
}

void greeting (object who)
{
  object	ob;

  if (!who || environment(who) != environment()) return;
  if (PK_D->get_pk_time(who)) {	// 江洋大盗一名
    message_vision ("$N喝道: $n, 今天碰到我算你倒霉, 纳命来吧!!\n",
		    ob=this_object(), who);
    ob->kill_ob(who);
    command("follow "+who->query("id"));
  }
}

int do_apply (string arg)
{
  if (!arg || arg != "license") {
    write ("九省巡捕告诉你: 你想申请什么? PK 执照是 pk license 啊!\n");
    return 1;
  }
  message_vision ("$N向九省总巡捕申请了一张ＰＫ执照。\n", this_player());
  new(PK_LICENSE)->move(this_player());
  return 1;
}
