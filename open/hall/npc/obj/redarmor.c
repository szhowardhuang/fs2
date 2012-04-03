#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;37m±ÌÑ©Ä§¼×[0m", ({ "snow armor", "armor" }) );
        set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("long", "´Ë¼×Ïà´«ÊÇ´ÓÇ§Äêº®±ù¾«Á¶¶ø³É£¬ÓÐ×ÅÏàµ±µÄ·ÀÓùÁ¦¡£");

                set("material", "iron");
                set("value", 2000);
                set("armor_prop/armor", 10);
        }
        setup();
}
