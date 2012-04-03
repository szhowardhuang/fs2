#include <weapon.h>
#include <ansi.h>

inherit EQUIP;

void create()
{
         set_name( "Ä§Ç„ÒÂ" , ({ "daemon cloth","cloth" }) );
         set_weight(500);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "¼þ");
                 set("value",5000);
                 set("material", "cloth");
                 set("armor_type", "cloth");
                 set("armor_prop/armor",5);
         }
         setup();
}
