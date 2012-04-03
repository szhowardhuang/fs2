#include <weapon.h>
#include <ansi.h>

inherit	UNARMED;

void create()
{
        seteuid(getuid());
        set_name(YEL"土色灵爪"NOR,({"soil claw","claw"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","土爆波所使用的宝爪，土光隐隐发出微微光芒，令人心神宁静。\n");
                set("value",1000000);
                set("material", "gold");
                set("wield_msg", "拿起$n,$N觉得有一股灵光注入了身躯。\n");
                set("unwield_msg", "$N将手中的$n小心的收起。\n");
        }
        init_unarmed(100);

        setup();
}
