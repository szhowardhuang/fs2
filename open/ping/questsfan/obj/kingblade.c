//太皇刀─蓝牙------by dhk 2000.4.22
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(""HIY"太皇刀"NOR"─"HIB"蓝牙"NOR"", ({ "kingblade bluetooth","kingblade","bluetooth" }) );
    set_weight(1000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "这是一把曾由比轩辕皇帝时代更早的太皇帝随身兵器，相传\n"
                  +"此兵器会令使用者发狂，而且挥舞之时会出现似残神蓝虎之\n"
                  +"利牙的光影，只要跟其他兵器相交锋，其兵器会被蓝牙粉碎\n");
       set("unit", "把");
       set("value", 150000);
       set("no_get",1);
       set("no_auc",1);
       set("no_sell",1);
       set("no_drop",1);
       
      }
    setup();
}
