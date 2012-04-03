#include <weapon.h>
#include <weapon.h> 

inherit STICK;

void create()
{
        set_name( "»¢ÑÀË«½Ú¹÷" , ({ "tiger stick","stick"}) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ù");
                set("long", "Ò»¸ù¸ÖÖÆµÄË«½Ú¹÷£¬Î²¶ËÔò¼ÓÉÏĞ°»¢µÄ»¢ÑÀ£¬ÔöÇ¿¹¥»÷Á¦¡£\n");
                set("value", 6000);
                set("material", "steel");
        }
        init_stick(30);

        set("wield_msg", "[36mÖ»¼ûµ½$N´óºÈÒ»Éù£¬$n±ã´Ó±³ºóµÄ²¼°üÀï·ÉÔ¾¶ø³ö[0m¡£\n");
        set("unwield_msg", "$NÏò¿ÕÖĞÒ»Å×£¬$n±ã×Ô¶¯·É»Ø²¼°üÄÚ¡£\n");

        setup();
}                   