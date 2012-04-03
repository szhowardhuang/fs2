#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37ma[0m" , ({"wind helme","helme"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄÕ½´ø¡£\n");
   set("wear_msg", "$N½«$nÌ×ÉÏ£¬"HIW"¿ñ·çÕ½´ø"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÕ½´ø"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/stabber",3);
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
