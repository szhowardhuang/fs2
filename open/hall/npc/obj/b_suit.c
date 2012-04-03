#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;32mÉÁÂÌ¾¢×°[0m", ({ "green suit", "suit" }) );
        set_weight(2000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ì×");
                set("long", "´Ë¼×ÉÁ×ÅÂÌÃ¢£¬ÓĞ×ÅÊ®·ÖÓÅÁ¼µÄ·ÀÓùÁ¦¡£");

                set("material", "cloth");
                set("value", 2000);
                set("armor_prop/armor", 15);
        }
        setup();
}
