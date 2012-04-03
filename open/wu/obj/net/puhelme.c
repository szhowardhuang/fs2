#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37ma[0m" , ({"purple helme","helme"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÏÉ¹Ú¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬$NÉíÉÏµÄ$nÉ¢·¢µÄÁéÆø½«$N°üÎ§¡£\n");
   set("armor_prop/dodge",3);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
      set("armor_prop/armor",7);
        set("unit", "¶¥");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
int query_autoload()
{
 return 1;
}
