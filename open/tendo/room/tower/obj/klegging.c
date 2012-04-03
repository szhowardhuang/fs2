inherit EQUIP;
#include <ansi.h>
void create()
{
 set_name(HIW"×ÏÓðÁúË¿¼×"NOR,({"dragon legging","legging"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼þ");
        set("value",4000);
        set("material","leather");
        set("armor_type","leggings");
 set("armor_prop/armor",6);
 set("armor_prop/attack",2);
 set("armor_prop/parry",2);
        }
        setup();
}


