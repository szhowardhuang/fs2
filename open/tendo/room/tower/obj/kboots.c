#include <ansi.h>
inherit EQUIP;
void create()
{
 set_name(MAG "×ÏÓðÁúË¿Ñ¥" NOR,({"dragon boots","boots"}));
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit","Ë«");
                set("value",4000);
 set("armor_prop/dodge",3);
 set("armor_prop/move",3);
                set("material","leather");
                set("armor_type","boots");
}
setup();
        }


