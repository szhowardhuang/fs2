#include <ansi.h>
#include <armor.h>
inherit FINGER;
object me=this_player();
void create()
{
        set_name(MAG"忍者治愈戒"NOR,({"ninja ring","ring"}));
        set_weight(200);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "只");
        set("value",0);
        set("long","传说中能让佩带者在休息时迅速恢复体力的戒指。\n");
        set("material","steel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
        this_object()->set("armor_prop/armor", 5);
        this_object()->set("armor_prop/attack", 5);
        this_object()->set("armor_prop/dodge",5);
        this_object()->set("armor_prop/parry",5);
        this_object()->set("armor_prop/dagger",10);
        this_object()->set("armor_prop/throwing",10);
        set_heart_beat(1);
}
void heart_beat()
{
 if( !me->is_fighting() && query("equipped"))
{
 if(random(100) > 75)
   {
me->receive_curing("kee",10);
me->receive_heal("kee",10);
}}}

