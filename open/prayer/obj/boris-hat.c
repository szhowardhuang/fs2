#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name("[32mÇ¬À¤Í·´ø[0m", ({ "boris hat", "hat" }) );
        set_weight(4000);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ê¥»ğ½Ì½ÌÖ÷×¨ÓÃµÄÍ·²¿·À»¤ÓÃ¾ß¡£\n");
                set("unit", "Ìõ");
                set("value",150000);
                set("material", "fur");
            set("wear_msg","[36m$NÒ»´÷ÉÏÁË$n£¬[35mÇ¬À¤ØÔÏó[36mÓ¿ÏÖ£¬ÎòĞÔÙ¿µØÌá¸ßÁËĞí¶à¡£[0m\n");
                set("armor_type", "head");
                set("armor_prop/armor", 10);
                
        }
        setup();
}                 
