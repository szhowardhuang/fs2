#include <weapon.h>
#include <ansi.h>

inherit BOW;

void create()
{

 set_name(HIR"龙蜒"HIY"神弓"NOR,({"dragon bow","bow"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
         set("long","一把由龙蜒所制成的弓。\n");

set("material","steel");
        }
init_bow(60);
set("value",1);
setup();
}
void init()
{
        add_action("do_perform","supershoot");
}
int do_perform()
{
        object me,*target,room;
        int i,j,k,l,damage;

        me=this_player();
        if(random(2)) {
        damage=1000; }
        else {
        damage=500;
        }
        room= environment(me);
target = me->query_enemy(room);
i=sizeof(target);
if(me->query("family/family_name")!="射日派")
                 return notify_fail("你无法使出此弓的特级密技!!!\n");
if(!me->is_fighting()) return notify_fail("只有在战斗中才能使用\n");
if(80>random(100)) {
        message_vision("

          $N"HIR"狂喝一声 : "BLINK+HIY"「龙  啸  九  天”"NOR"

       "HIR" 手中龙蜒神弓化变成一条青龙往敌人飞去，一时天昏地暗

       "HIR"只见到青龙快速的在敌人的身上点了几下，每个都喷出血来。

       \n\n"NOR,me);
        for(j=0;j<i;j++)
        {
             if(!target[j]) continue;
            if( target[j]->is_character() && !target[j]->is_corpse() && living(target[j]))
            {
            target[j]->add("kee",-damage);
            me->kill_ob(target[j]);
            COMBAT_D->report_status(target[j],1);
            }
        }
} else {
message_vision(HIW"结果敌人只造成一点点伤害很快就恢复了。\n"NOR,me);
}
if(me->query("id")!="master lee") {
            me->start_busy(1);
}
  return 1;
}
