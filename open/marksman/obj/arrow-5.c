#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name("ม๊ฯ๖ผý",({"rise arrow","arrow"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","ดü");
                set("base_unit","ึง");
set("material","copper");

        }
init_arrow(30);
set_amount(300);
set("value",0);
        setup();
}
