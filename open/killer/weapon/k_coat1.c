#include <armor.h>
inherit EQUIP;

void create()
{
   set_name("É±ÊÖÅû·ç",({"killer surcoat","surcoat"}));
   set_weight(1000);
   set("armor_type","cape");
   if( clonep() )
            set_default_object(__FILE__);
   else {
   set("unit", "¼ş");
   set("value",10000);
   set("material","leather");
   set("armor_prop/dodge",3);
   set("armor_prop/armor",3);
        }
        setup();
}