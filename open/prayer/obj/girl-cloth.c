#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("圣女玉衣",({"girl-cloth","cloth"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 20000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之后,，全身觉得轻飘飘的，非常舒服。\n");
        set("armor_prop/armor", 18);
        set("armor_prop/dodge", 1);
        set("armor_prop/force", 1);
        set("long","
西域特殊的织料再用西域翠玉混合制成,在身上主要的经脉均做了防护。
可以有效防止经脉方式的攻击。后面则绣有女娲娘娘的图象。\n");
        }
         setup();
}





