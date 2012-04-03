// buddha_staff.c

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("ÆĞÌáôÂôÄ",({"puty pullium","pullium"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼ş");
        set("value",10000);
        set("material","cloth");
        set("armor_type","cloth");
        set("armor_prop/armor",70);
        set("armor_prop/dodge",10);
        }

        setup();
}
