#include <ansi.h>
inherit NPC;

void create()
{
        seteuid(getuid());      // 这行一定要
        set_name("叶二娘", ({ "mother-ya","ya" }) );
        set("attitude","aggressive");
        set("clan_kill",1);
        set("title","四大恶人之次");
        set("nickname",HIG"无恶不作"NOR);
        set("race", "人类");
        set("gender", "女性");
        set("age", 35);
        set("long", "
一个颇有姿色的中年美妇, 一弯柳叶眉, 和柔和的眼神,
你很难相信她就是天下四恶之一的叶二娘。\n");
        set("str", 30);
        set("cor", 30);
        set("max_kee", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 15);
        set("combat_exp", 900000);
        set_skill("blade", 90);
        set_skill("parry", 70);
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("force", 90);
        set_skill("sixforce",100);
        set_skill("gold-blade", 100);
        set_skill("sha-steps", 100);
        map_skill("blade","gold-blade");
        map_skill("dodge","sha-steps");
        map_skill("parry","gold-blade");
        set("chat_chance", 8);
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: this_object(),"special_attack" :),
        }));
        set_temp("apply/armor", 80);

        setup();
        add_money("gold",10);
        carry_object("/open/tailong/obj/liu-blade")->wield();
}


 int special_attack()
 {
   object ob,me;
   int k;
   me = this_object();
   k = random(10);
   ob=this_object()->query_enemy();
   if(k > 7)
   {
   message_vision(HIR"叶二娘藉着地形之利使出"HIY"‘狂风拂柳刀’"HIR", 你一不留意, 身中数刀!!\n\n"NOR,this_object());
   ob->add("kee",-100);
   }
   else
   {
   message_vision(HIY"\n叶二娘运起‘天魔疗伤心法’不可思议的光芒从叶二娘身上发出，叶二娘的创伤恢复了!\n"NOR,this_object());
me->add("kee",500);
me->add("max_kee",100);
   }
  return 1;
  }
void die()
{
   object winner;
   winner= query_temp("last_damage_from");
   tell_object(winner,
HIY"你在叶二娘身后发现的一个密道, 连忙走了进去..\n"NOR);
   winner->move("/open/main/room/to_chun2.c");
        ::die();
        return 0;
}
