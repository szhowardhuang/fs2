
#include <combat.h>
#include <ansi.h>
#include <mudlib.h>
#define MASTER "suzukiami"
inherit NPC;
inherit SSERVER;

int do_ascend(object me);
int do_descend();

void create()
{
  set_name(HIY"皮卡丘"NOR, ({ "pe-ca","ca" }) );
set("long",@LONG
你所看到的是神奇宝贝皮卡丘
牠是电击型的神奇宝贝
绝招是十万伏特和快速移动
要不骑的话，请打un_invocation
LONG);
  set("unit","只");
  set("value","100");
  set("race", "野兽");
  set("gender","雄性");
  set("combat_exp",10000000);
  set("no_exp",1);
  set("age",24710);
  set("cor",40);
  set("str",20);
  set("kee",100000);
  set("max_kee",100000);
  set("sen",70000);
  set("max_sen",70000);
  set("gin",45000);
  set("max_gin",45000);
  set("force",32000);
  set("max_force",32000);
  set("bellicosity",1000);
  set("attitude","friendly");
  set_temp("apply/armor",100);
  set_temp("apply/damage",80);
  set("verbs",({"bite","claw"}));
  set("limbs", ({ "龙首", "龙爪", "龙身" , "龙腿" , "龙尾" }) );
  set("force_factor",25);
  set_skill("dodge",700);
  set_skill("parry",400);
  set_skill("unarmed",500);

  setup();

}


void init()
{
add_action("do_descend","un_invocation");
}

int do_ascend(object me)
{
        string name;
        if(!me) me=this_player();
        if(!me) return 0;
        if(!userp(me)) return 0;
        name=geteuid(me);
        if (name != MASTER && !wizardp(me) && userp(me))
           return notify_fail("你不是这座骑的主人("+MASTER+")无法骑他!!!\n");
        if ( me->query_temp("marks/ascend") )
               return notify_fail("你无法骑在别人的座骑身上呀。\n");
message_vision(HIY+"$N"+HIY+"大声叫道:上吧!"+this_object()->query("name")+HIY+",
一道闪光从神奇宝贝球里出现,
"+this_object()->query("name")+HIY+"出现在$N"HIY"眼前!!\n"NOR,me);
        me->set_temp("marks/ascend",1);
        me->add_temp("apply/dodge",30);
        me->add_temp("apply/parry",30);
        me->add_temp("apply/unarmed",30);
        me->add_temp("apply/attack", 30);
        me->add_temp("apply/defense",30);
        me->add_temp("apply/damage",30);
        me->add_temp("apply/armor", 30);
        this_object()->set_leader(me);
        this_object()->set("master",me);
        set_heart_beat(1);
        if(!query_heart_beat()) tell_object(me,"心跳启动失败!!\n");
        me->add_temp("ride_name",HIW"(正骑着"NOR+this_object()->name()+HIW")"NOR);
        return 1;
}

int do_descend()
{
        object me;
        string *name;

        me=query("master");
        if(me){
        if(geteuid(this_player())!=MASTER && !wizardp(this_player())){
          if(present(geteuid(me),environment(this_object()))){
            message_vision("$N说道:竟敢命令我的神奇宝贝, 去死吧!!!\n",me);
           present(geteuid(me),environment(this_object()))->kill_ob(this_player());
          }
          this_object()->fight_ob(this_player());
          return 1;
        }
        if ( !me->query_temp("marks/ascend") )
                return notify_fail("你没在座骑上耶。\n");
message_vision(HIG"$N"HIG"向"+this_object()->query("name")+HIG"丢出了神奇宝贝球,
"+this_object()->query("name")+HIG"化成一道闪光消失在宝贝球里!!\n"NOR,me);
        me->delete_temp("marks/ascend");
        me->delete_temp("ride_name");
        if(me->query_temp("apply")){
        me->add_temp("apply/dodge",-30);
        me->add_temp("apply/parry",-30);
        me->add_temp("apply/unarmed",-30);
        me->add_temp("apply/attack", -30);
        me->add_temp("apply/defense",-30);
        me->add_temp("apply/damage",-30);
        me->add_temp("apply/armor", -30);
        }
//        move(environment(me));
        set_heart_beat(0);
        tell_object(me,sprintf("
%s对你说道：我已经功成身退，先回家睡觉啰!!!\n",this_object()->name()));
        }
        destruct(this_object());

        return 1;
}

void heart_beat()
{
  object enemy,who,user;
  int i,dodge;
  user=query("master");
  if(!user)
  {
    set_heart_beat(0);
    destruct(this_object());
    return ;
  }
  if(!living(user) || user->is_ghost())
  {
    die();
    return ;
  }
  if(!present(geteuid(user),environment(this_object())) && environment(user))
  {
    message_vision("$N"HIY"化成一道黄光，往天际飞去!!!\n"NOR,this_object());
    this_object()->move(environment(user));
    message_vision(HIY"一道黄光由天空降下，$N"HIY"出现在众人眼前!!\n"NOR,this_object());
  }

 /* if( user->is_fighting() )
  {
    enemy=offensive_target(user);
    if(!enemy) return ;
    if(!present(enemy->query("id"),environment(this_object()))) return ;
    if( random(10) > 2 )
    {
      if(random(10) > 5)
      {
message_vision(HIW+"$n使出了十万伏特攻击向$N射了过去!!\n"+NOR,enemy,this_object());
      message_vision(HIC+"$N闪躲不及 ,被烧得的全身焦黑。\n"+NOR,enemy);
      enemy->receive_damage("kee", 500);
      enemy->start_busy(random(2));
      COMBAT_D->report_status(enemy);

      }else{
message_vision(HIW+"$n使出了十万伏特攻击向$N射了过去!!\n"+NOR,enemy,this_object());
      message_vision(HIC+"只见$N飞身侧闪 ,轻轻避开疾光的攻击...\n"+NOR,enemy);

     }
    }
  }*/
        return ::heart_beat();
}
void die()
{
        do_descend();
        return;
}
int accept_fight(object me) {
        return notify_fail("这是别人的财产, 你杀不得!\n");
}

int accept_kill(object me) {
        return notify_fail("这是别人的财产, 你杀不得!\n");
}


