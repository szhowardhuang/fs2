#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
    set_name("[35mÊóØ×[0m",({"mouse bite","mouse","bite"}));
    set_weight(300);
  if( clonep() )
                set_default_object(__FILE__);
        else {
    set("unit", "Ö»");
    set("base_unit","Ö»");
    set("base_value",700);
    set("value",700);
    set("material", "steel");
   }
    init_throwing(90);
    set_amount(2);
    setup();
}
