#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37m¡õ[0m" , ({"purple surrcoat","surrcoat"}));
   set_weight(10000);
   set("armor_type","cape");
   if( clonep() )
           set_default_object(__FILE__);
   else {
   set("unit", "¼ş");
   set("material","leather");
   set("value",100000);
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÏÉÅû¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬$NÉíÉÏµÄ$nÉ¢·¢µÄÁéÆø½«$N°üÎ§¡£\n");
   set("armor_prop/armor",6);
   set("armor_prop/dodge",3);
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
