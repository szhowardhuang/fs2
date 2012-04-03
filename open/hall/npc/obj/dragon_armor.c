#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("[1;34mÇàÁúÁÛ¼×[0m", ({ "dragon armor", "armor" }) );
        set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("long", "´ËÁú¼×Ïà´«ÊÇ´ÓÇ§ÄêÇàÁúÑıÉíÉÏ°ÎÁÛÖÆ³É£¬´©ÉÏ´Ë¼×±ã¿Éµ¶Ç¹²»Èë£¬ÎŞ\n"
                "ËùÅûÃÒ¡£\n");

                set("material", "gold");
                set("value", 2000);
                set("armor_prop/armor", 15);
        }
        setup();
}
