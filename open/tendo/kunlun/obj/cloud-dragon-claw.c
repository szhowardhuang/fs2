#include <weapon.h>
#include <ansi.h>
inherit UNARMED;

void create()
{
                set_name("ÔÆÁú»Ã×¦", ({ "cloud-dragon claw" ,"claw" }) );
                set_weight(1500);
                if( clonep() )
                set_default_object(__FILE__);
                else {
                set("long", "\n");
                set("unit", "°Ñ");
                set("value", 300000);
                set("material", "blacksteel");
                set("type", 1); 
                }
                init_unarmed(75);
                setup();
}

