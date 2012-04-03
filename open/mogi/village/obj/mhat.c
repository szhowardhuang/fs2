#include <weapon.h>
#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("Ø²»¤½í",({"daemon hat","hat"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","¼þ");
                set("value",1000);
                set("material","cloth");
                set("armor_type","head");
                set("armor_prop/armor",10);
        }
        setup();
}
