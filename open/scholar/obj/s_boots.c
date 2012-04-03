#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name("Ñª±ª\Ñ¥",({"boots"}));
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit","Ë«");
                set("value",12000);
// Swy QC 98/3/16
                set("armor_prop/armor",4);
                set("armor_prop/dodge",2);
                set("armor_prop/move",3);
                set("material","leather");
                set("long","´ËÐ¬È¡ÏÂÑª±ª\Ã«Æ¤ËùÖÆ¡£\n");
                setup();
        }
}
