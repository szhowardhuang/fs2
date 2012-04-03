#include <ansi.h>
inherit EQUIP;

void create()
{
 set_name(HIB"×ÏÓğÁúË¿½í"NOR,({"dragon hat","hat"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼ş");
        set("value",4000);
        set("material","leather");
        set("armor_type","head");
 set("armor_prop/armor",6);
 set("armor_prop/parry",2);

        }
        setup();
}


