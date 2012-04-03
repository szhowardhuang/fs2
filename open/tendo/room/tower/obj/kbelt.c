#include <ansi.h>
inherit EQUIP;
void create()
{
 set_name(HIY"×ÏÓğÁúË¿Ñü´ø"NOR,({"dragon belt","belt"}));
 set_weight(100);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "¸¶");
            set("armor_type", "waist");
            set("material", "leather");
            set("value", 4000);
            set("armor_prop/armor",5);
     }
}


