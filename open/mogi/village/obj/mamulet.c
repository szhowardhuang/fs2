#include <weapon.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name("ÑªÑý¾±»·", ({ "daemon amulet", "amulet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 2300);
                set("material", "gem");
                set("armor_type","neck");
                set("armor_prop/armor", 15);
        }
        setup();
}
                        
