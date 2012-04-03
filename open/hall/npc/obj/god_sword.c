#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("[1;33mÉĞ·½±¦½£[0m", ({ "god sword", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("long", "»ÊµÛËùÅä´øµÄ±¦½££¬¾İËµ³Ö´Ë½£±ãÓĞÈçÊ¥ÉÏÇ×ÁÙ¡£½£ÇÊÉÏÏâ×ÅÒ«ÑÛµÄ±¦\n"
                "Ê¯£¬¶ø½£·æÔò·¢³ö½ğ»ÆÉ«µÄ½£Æø¡£\n");
                set("value",10000);
                set("material", "gold");
        }
        init_sword(20);

        set("wield_msg", "$N¡¸ïÏ¡±µØÒ»Éù¡«¹§Çë³ö$nÎÕÔÚÊÖÖĞ¡£\n");
        set("unwield_msg", "$N½«ÊÖÖĞµÄ$n½÷É÷µØ²åÈë¡«Ê¥Áú½£ÇÊ¡£\n");

        setup();
}
