//Qc by Anmy /98/7/6
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
          set_name("狂雷",({"thunder claw","claw"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","这是一把爪子，戴上后会有很强的震撼力。\n");
                set("value",1000);
                set("material", "crimsonsteel");

        set("wield_msg", "$N将$n载在手上，全身的穴道被打通了，好像狂战士一样。\n");
        set("unwield_msg", "$N将手上的$n卸了下来，震撼力消失了，全身变回原来的样子。\n");
        }
        init_unarmed(35);

        setup();
}
