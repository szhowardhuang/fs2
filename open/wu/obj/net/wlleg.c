#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;37m¡õ[0;37mg[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[1;37m¡õ[0;37m¡õ[0m",({"wind legging","legging"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñÊ¹ÓÃ·çÑÒÊ¯Ëù´òÔìµÄ»¤Ï¥¡£\n");
   set("wear_msg", "$N½«$n°óÉÏ£¬"HIW"¿ñ·çÕ½Ï¥"NOR"µÄ·¢³öµÄ¹âÃ¢×¢Èë$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÈ¡ÏÂ£¬"HIW"¿ñ·çÕ½Ï¥"NOR"µÄ¹âÃ¢Á¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
        set("unit","¼ş");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor",6);
        set("armor_prop/stabber",2);
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
