#include <weapon.h>
#include <ansi.h>

inherit EQUIP;
void create()
{
        set_name("ÑýÊÖ»·",({"daemon wrists","wrists"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","¼þ");
                set("value",3000);
                set("material","jade");
                set("armor_type","wrists");
                set("armor_prop/armor", 10);
        }
        setup();
}
