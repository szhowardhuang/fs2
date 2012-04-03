#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name("ÖìÈ¸¼ý",({"red arrow","arrow"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","´ü");
                set("base_unit","Ö§");
set("material","iron");

        }
init_arrow(20);
set("value",0);
set_amount(300);
        setup();
}
