inherit EQUIP;
#include <ansi.h>
void create()
{
        seteuid(getuid());
        set_name("½ð÷ëÈí¼×" , ({ "golden armor","armor" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 100000);
                set("material", "cloth");
                set("armor_type", "cloth");
		set("armor_prop/armor",21);
                set("armor_prop/parry",5);
              }



}
