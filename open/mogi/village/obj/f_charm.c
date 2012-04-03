//封魔符...给玩家使用的道具....可以使对手busy...  made by eva
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("封魔符", ({"charm"}));
    set_weight(30);
        set("long","画满符咒的黄纸, 朝对象使用的话可以暂停对手的动作!
使用方法:freeze <对象>\n");
        set("unit","张");
        set("base_unit","张");
     set("value",500000);
        set_amount(1);
    setup();
}

void init()
{
    if (this_player()==environment())
        {
        add_action("do_freeze","freeze");
        }
}

int do_freeze(string arg)
{
    object me,target;
    me=this_player();
    if( !me->is_fighting() && !me->is_killing() )
        return notify_fail("现在不是战斗中, 你不能使用封魔符!\n");
    if (!arg)
        return notify_fail("你想要封住谁呀?\n");
    target=present(arg,environment(me));
    if (!target->is_character() || target->is_corpse())
        return notify_fail("对非生物使用封魔符是没有用的!!\n");
    if(target->is_busy())
         return notify_fail("敌人的行动被封住了不用在用封魔符了!!\n");
    if (me->query("sen") < (int) (me->query("max_sen") * 0.6) || me->query("sen") < 60)
        return notify_fail("你没有足够的精神去念咒!\n");
    if (me->is_fighting(target) || me->is_killing(target))
        {
        message_vision(HIW"$N口中念道: 天 地 之 灵 听 我 之 命～\n"NOR,me,target);
        me->start_busy(1);
        message_vision(HIY"$N丢出一张符咒, 大喝：～～～封～～～\n"NOR,me,target);
     if(arg=="fire king" || arg=="king"){
        me->add("sen",-40);
        add_amount(-1);
      write(HIC"结果封印刚飞到一半，就被焚天魔王的"HIR"极火真气"HIC"焚毁!!\n"NOR);
        return 1;
                                        }
     else if(random(100)>50) {
      me->add("sen",-40);
      message_vision(HIY"$n瞬时发出强大的内力使$N的封魔符法力,无法发挥!!\n"NOR,me,target);
      add_amount(-1);
      return 1;
      }
     else {                                   
       target->start_busy(3);
    me->add("sen",-40);
        message_vision(HIC"$n受到$N封魔符的封印, 变得无法动弹!!\n"NOR,me,target);
        add_amount(-1);
        return 1;
          }
        }
    else
        {
        return notify_fail("你又没有在攻击他, 封住他干嘛?\n");
        }
}
