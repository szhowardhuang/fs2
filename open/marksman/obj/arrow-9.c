#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name("ùmôá¼ý",({"bird arrow","arrow"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","´ü");
                set("base_unit","Ö§");
set("material","steel");
set("value",0);

        }
init_arrow(50);
set_amount(300);
        setup();
}
