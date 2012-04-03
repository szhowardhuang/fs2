#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("[1;34mÂäÔÆÇ¹[0m", ({ "cloudy lance", "lance" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("long", "Ç¹Í·ÒşÒşÍ¸³öÀ¶¹â£¬ÊÇ°Ñ²»¿É¶àµÃµÄÉñ±øÀûÆ÷¡£\n");
                set("value",10000);
                set("material", "blacksteel");
        }

        init_hammer(30);

        set("wield_msg", "$N¡¸É²¡±µØÒ»Éù¡«$nÒÑÎÕÔÚÊÖÖĞ¡£\n");
        set("unwield_msg", "$N½«ÊÖÖĞµÄ$n“dµ½Éíºó¡£\n");

        setup();
}
