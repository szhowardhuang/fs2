#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  object ob;
  set_name("红叶组一级杀手",({"red killer","killer","red"}) );
  set("long","他在此担任守护红叶组的工作，自然手下功夫不弱 \n");
  set("race", "人类");
  set("gender","男性");
  set("combat_exp",180000);
  set("age",20);
  set("title","黑牙联的成员");
  set("class","killer");
  set("cor",30);
  set("cps",30);
  set("str",20);
  set("kee",1000);
  set("max_kee",1000);
  set("force",700);
  set("max_force",700);
  set("force_factor",3);
  set("chat_chance",10);
  set("bellicosity",200);
  set_skill("rain-throwing",50);
  set_skill("throwing",55);
  set_skill("blackforce",35);
  set_skill("force",45);
  set_skill("dodge",55);
  set_skill("parry",55);
  map_skill("force","blackforce");
  map_skill("throwing","rain-throwing");
 setup();
    add_money("gold",2);
    ob=carry_object("/open/killer/obj/lustar");
    ob->add_amount(60);
    ob->wield();
    ob=carry_object("/open/killer/weapon/k_cloth2.c")->wear();
}
void init()
{
    object ob;
    ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);   }
}
int accept_kill(object ob)
{
message_vision( this_object()->name()+"说:先接最利害的五招吧！\n",ob);
  add("bellicosity",700);
  command("cmd bellup");
   return 1;

}
int accept_fight(object me)
{
    object ob,guard;
    ob=this_object();

    guard=present( "guard 2",environment(ob) );
     if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
    else {
    tell_room(environment(me),"一起上！有人找碴!给我拿下 \n"),
    message_vision(HIB"\n红叶组一级杀手看到好友有难，马上向$N攻过来！\n"NOR,me
);
     guard->fight_ob(me);
    return 1;
   }
}
void greeting(object ob)
{
  if( ob->query("class")=="killer")    
  {
    command("smile "+ob->query("id"));  
  }
  else  
  {
    command("say 擅闯红叶组！到底有什么事？ \t");
    command("hmm"); 
  }
}
