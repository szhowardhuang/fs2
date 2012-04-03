#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name(HIG"绿色灵剑"NOR,({"wood sword","sword"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","木燃落所使用的宝剑，绿光闪闪夺目，令人无法直视。\n");
                set("value",1000000);
                set("material", "gold");
                set("wield_msg", "拿起$n,$N觉得有一股灵光注入了身躯。\n");
                set("unwield_msg", "$N将手中的$n小心的收起。\n");
        }
        init_sword(100);

        setup();
}

