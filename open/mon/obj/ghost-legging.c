#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
                set_name(HIY"妖幻护膝"NOR, ({ "ghost legging" ,"legging" }) );
                set_weight(50);
                if( clonep() )
                set_default_object(__FILE__);
                else {
                set("long", "千年树妖－舞风扬所拥有，拥有绝佳的防护力的护膝。\n");
                set("unit", "双");
                set("value", 300000);
                set("material", "steal");
                set("armor_type", "leggings");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
                set("armor_prop/parry", 5);
                set("armor_prop/unarmed", 5);
                set("armor_prop/force", 10);
                set("wear_msg", HIW"$N双脚轻轻装上了护膝，$n"HIW"已舒适的穿在"HIW"$N的脚上。\n"NOR);
                set("unequip_msg", HIW"$N脱下了$n"HIW"$N"HIW"的防护力显得变弱了。\n"NOR);

                }
                setup();
}
  

