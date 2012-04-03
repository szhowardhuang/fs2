#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("[1;31m³àÑª½£[0m", ({ "blood sword", "sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("long", "Ò»°ÑÒÔ³à½ğºÍĞşÌú»ìºÏÁ¶ÖÆµÄ½££¬ÊÇ°ÑÄÜ¡«Ï÷½ğ¶ÏÓñÖ®ÀûÆ÷¡£");
                set("value",10000);
                set("material", "blacksteel");
        }
        init_sword( 50);

        set("wield_msg", "$NÊÖÖĞ[1;31m³àÑª½£[0mÉ¢·¢³öÑ£Ä¿µÄºì¹â¡«¡«\n");
        set("unwield_msg", "$NÊÖÖĞµÄ$nµÄºì¹â»º»ºÍËÈ¥¡«\n");

        setup();
}
