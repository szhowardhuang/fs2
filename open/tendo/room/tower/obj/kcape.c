#include <ansi.h>
inherit EQUIP;

void create()
{
 set_name(HIY"×ÏÓğÁúË¿²Ê´ø"NOR,({"dragon cape","cape"}));
        set_weight(3000);
        if ( clonep())
                set_default_object(__FILE__);
        else {
                set("unit","Ìõ");
                set("material","silk");
                set("value", 320);
                set("armor_type", "cape");
                set("armor_prop/armor",6);

        }
        setup();

}


