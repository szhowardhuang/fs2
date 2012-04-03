// Qc by Anmy 98/7/6 
#include <armor.h>
#include <ansi.h>
inherit HEAD;
object user;
void create()
{
        set_name( HIW "Ë®¾§Í·¿ø" NOR ,({"pebble hat","hat"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
                set("value",2000);
                set("material","gem");
                set("armor_prop/armor",8);
        setup();
}}
