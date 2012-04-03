#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[0m" , ({"wind cloak","cloak"}));
   set_weight(10000);
   set("armor_type","cape");
   if( clonep() )
           set_default_object(__FILE__);
   else {
   set("unit", "¼ş");
   set("material","leather");
   set("value",100000);
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄÅû·ç¡£\n");
   set("wear_msg", "$N½«$nÅûÉÏ£¬"HIW"¿ñ·çÕ½Åû"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIW"¿ñ·çÕ½Åû"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",6);
   set("armor_prop/stabber",3);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        }
        setup();
}
int query_autoload()
{
 return 1;
}
