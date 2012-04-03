#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        seteuid(getuid());
        set_name("[33mÁúĞÎÈı½Ú¹÷[0m",({"dragon-stick","stick"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
        set("long","ÕâÊÇÒ»±ú¸ÖÖÆµÄÈı½Ú¹÷£¬Î²¶Ë²¿·ÖÔòÒÔ»Æ¼×½ğÁúµÄ¹ÇÍ·ÖÆ³ÉÁúĞÎ£¬½åÒÔÌá¸ß¹¥»÷Á¦£®\n");

                set("value",30000);
                set("material", "steel");
        set("wield_msg", "$N´Ó²¼°üÖĞ³é³öÁË$n£¬ö®Ê±¼äÄã¾õµÃ[36mÁúÇ¿´óµÄÁ¦Á¿¹àÈëÁËË«±Û[0m¡£\n");
        set("unwield_msg", "$N½«$n·Å½øÑü¼äµÄ²¼°ü ¡£\n");
        }
        init_stick(90);
        setup();
}                            