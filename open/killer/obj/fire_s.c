#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user;
int be,bb,inn,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIR"火魔剑"NOR,({"iceger"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","此乃至热之物,能给予敌人致命伤害．\n");

                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
        }
        init_sword(255);
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     { 
        user = this_player();
        message_vision(HIR"$N将火魔剑握在手上，全身已被炎气笼罩。\n"NOR,user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N你居然抛弃火魔神-伊佛力特？",user);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("[1m[31m$N运起体内熊熊真气,手中[37m破冰[31m以消失无踪。[0m\n",user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N画出一道剑花，剑归剑盒。"NOR,user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N画出一道剑花,手中火魔剑消失无踪。"NOR,user);
        set_heart_beat(0);
     }
}

void heart_beat()
{
  object *enemy,who;
  int i;
//  be = user->query("bellicosity",1);
  be = 1000;
  bb = (be/20);
  inn= user->query("int",1);
  sp = user->query("spi",1);
qq=(inn +sp) *2 /30;
 if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
    if( be > random(300) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if( environment(user) == environment(enemy[i]) )
      if( random(5000) > enemy[i]->query_skill("dodge") )
     {
      message_vision(HBRED"火魔神--*伊佛力特*，回复原形,直接冲向$N，瞬间陷入一片火海!!!"NOR,enemy[i]);
      enemy[i]->receive_damage("kee",qq+bb,user);
      COMBAT_D->report_status(enemy[i], 0);
     }else
      message_vision("[1m[33m一道火焰由火魔剑激发而出,可惜被$N体内真气所阻挡..[0m\n",enemy[i]);
     }
  }
  return;
}
