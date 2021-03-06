#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
   object ob;
   set_name("周八伯",({"eight uncle","eight","uncle"}) );
   set("long","此人不仅一身功夫了得, 而且精通歧黄之术, 是一位相当可怕的敌人\n");
   set("race", "人类");
   set("gender","男性");
   set("combat_exp", 600000);
   set("age",50);
   set("title","绿云组组长");
   set("class","killer");
   set("cor",30);
   set("cps",30);
   set("str",30);
   set("kee",2300);
   set("max_kee",2300);
   set("force",1500);
   set("max_force",1500);
   set("force_factor", 10);
   set("bellicosity",900);
   set_skill("rain-throwing",80);
   set_skill("throwing",85);
   set_skill("blackforce",75);
   set_skill("force",85);
   set_skill("shade-steps",90);
   set_skill("dodge",90);
   set_skill("parry",85);
   map_skill("dodge","shade-steps");
   map_skill("move", "shade-steps");
   map_skill("force","blackforce");
   map_skill("throwing","rain-throwing");

   set("chat_chance_combat", 20);
   set("chat_msg_combat", ({
           (:perform_action,"throwing.rain":),
   }));

   setup();
   add_money("gold", 10);
   ob=carry_object("/open/killer/obj/lustar");
   ob->add_amount(500);
   ob->wield();
   carry_object("/open/killer/weapon/k_cloth2.c")->wear();
}

void init()
{
   object me= this_player();
   ::init();
   if( me->query("id") == "ljen")
      call_out("greeting",1,me);
}

int accept_object( object me, object obj)
{
   string obj_name= obj->query("name");

   if( me->query_temp("ghost") != 3)            //还没杀死陈星辉的话就不处理
      return 1;

   if( obj_name == "陈星辉的头")
   {
      command("say hmm...这果然是陈星辉的头");
      me->set_temp("shead", 1);
   }
   else if( obj_name == "香火")
      me->set_temp("incense", 1);
   else if( obj_name == "金纸")
      me->set_temp("gpaper", 1);
   else if( me->query_temp("shead") && me->query_temp("incense") && me->query_temp("gpaper"))
   {
      command("say 东西都到齐了, 那就让我为开始为任盈盈超渡吧...");
      message_vision("只见周八伯又拿起他的铃铛, 燃香点烛, 口中念念有词...\n", me);
      message_vision("随即大喝一声, 只听见任盈盈的声音在远处响起\n", me);
      message_vision(HIB"谢谢$N的大恩大德, 小女子无以为报, 不过小女子在生前曾得到一些相当特别\n"NOR, me);
      message_vision(HIB"的药丸, 为了避免被别人发现, 所以就将它藏在你的棺木内, 小女子就以这些\n"NOR, me);
      message_vision(HIB"丹药当成对你的报答好了........"NOR, me);
      me->set_temp("ghost", 4);
   }
   else
      command("say 给我这个做什么。");
   return 1;
}
int accept_fight(object me)
{
   return 1;
}
int accept_kill( object me)
{
   object guard;

   add("bellicosity",700);
   command("cmd bellup");

   guard=present( "killer 2",environment(me) );
   if( !present( "killer 2",environment(me))||!living(guard))
      return 1;
   else
   {
      tell_room(environment(me),"一起上！有人找碴!给我拿下 \n"),
      message_vision(HIB"\n绿云组一级杀手看到组长有难，马上向$N攻过来！\n"NOR,me);
      guard->kill_ob(me);
      return 1;
   }
}
void greeting(object ghost)
{
   object me= ghost->query_leader();
   if( me->query_temp("ghost") == 1)  //只要能把鬼带来的人都会等于 1
   {
      command("say "+(me->query("gender")=="男性" ? "壮士" : "姑娘")+"看你印堂发黑, 似乎是被鬼上身了。");
      command("hmm");
      command("say 让我即刻升堂作法, 看看附身在你身上的鬼有什么话说。");
      message_vision("只见周八伯拿起铃铛, 燃香点烛, 口中念念有词...\n", me);
      message_vision("旋即一阵白烟从你头上冒出化身成人形......\n", me);
      ghost->delete_temp("invis");
      ghost->command("say 小女子生前是一名杀手, 某天到墓园逛逛时却被某人由背后偷袭...后来那个猪狗不如的东西竟然.....");
      ghost->command("cry "+ me->getuid());
      ghost->command("say 请"+(me->query("gender")=="男性" ? "壮士" : "姑娘")+"替小女子报仇, 据小女子所知, 那人正在黑风组总部作客。");
      ghost->command("say 如能替小女子报得大仇, 小女子愿以身相许...。");
      message_vision(HIW"任盈盈讲完这些话时, 又化成一阵烟消失了。"NOR, me);
      command("say 都听到了吧, 快去把那混帐东西的猪头带回来, 让我好好为她超渡一下, 别忘了再去土地公处买些香火 纸钱回来ㄚ。");
      me->set_temp("ghost", 2);
      destruct( ghost);
   }
}
