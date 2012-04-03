#include <ansi.h>
inherit NPC;
void create()
{
    set_name("十纹彩蝶", ({ "butterfly" }));
        set("race", "野兽");
	set("age", 15);
    set("long", "一只身上染有十种色彩的斑蝶..\n");
	set("str", 65);
        set("max_kee", 2400);
        set("kee", 2400);
        set("limbs", ({ "头部", "身体", "前脚" , "后脚" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",150000);
	set_temp("apply/armor", 70);
        set_temp("apply/attack", 30);
	set_skill("dodge",60);
          set_temp("apply/unarmed",30);
	setup(); 
        carry_object("/open/gsword/obj/f_item");
        carry_object("/open/gsword/obj/ff_item");
        set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
    if( 60 > random(300) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
 message_vision(HIW+"彩蝶洒了一些花纷在你身上!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee", 80,me);
      enemy[i]->start_busy(2);
      COMBAT_D->report_status(enemy[i], 0);
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}                             
