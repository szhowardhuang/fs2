#include <ansi.h>
inherit NPC;

void create()
{
        seteuid(getuid());      // 这行一定要
        set_name("关卡守卫", ({ "guard" }) );
        set("race", "人类");
        set("gender", "男性");
        set("age", 35);
        set("long", "他手中拿把穿长剑正守着大门。\n");
        set("str", 30);
        set("cor", 30);
        set("max_kee", 1000);
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("combat_exp", 300000);
        set_skill("sword", 60);
        set_skill("parry", 40);
        set_skill("dodge", 30);
        set_skill("force", 30);

        set_skill("shasword", 60);
        set_skill("sha-steps", 40);

        map_skill("sword","shasword");
        map_skill("dodge","sha-steps");

        set("chat_chance", 8);
        set("chat_msg",({
             "关卡守卫说道: 入关如登天，来人走这边。\n",
             "关卡守卫瞪了你一眼说: 想入关？能杀的了我再说吧。\n",
             "关卡守卫推了你一把说: 要进关不难，但是你有这个资格吗？\n",
        }) );
        set_temp("apply/armor", 80);

        setup();
        add_money("silver", 5);
        carry_object("/obj/longsword")->wield();
}

int accept_kill(object me)
{
  object ob,guard;
  ob=this_object();
  guard=present( "guard 2",environment(ob) );
  if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
  else {
  tell_room(environment(me),"一起上！有人找碴!给我杀了 \n"),
  message_vision(HIY"\n关卡守卫看到有人要硬闯，马上向$N攻过来！\n"NOR,me
  );
  guard->kill_ob(me);
  return 1;
  }
}
int accept_fight(object me)
{
  object ob,guard;
  ob=this_object();
  guard=present( "guard 2",environment(ob) );
  if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
  else {
  tell_room(environment(me),"一起上！有人找碴!给我杀了 \n"),
  message_vision(HIY"\n关卡守卫看到有人要硬闯，马上向$N攻过来！\n"NOR,me
  );
  guard->kill_ob(me);
  return 1;
  }
}
