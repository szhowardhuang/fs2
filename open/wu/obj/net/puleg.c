#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37my[0m",({"purple legging","legging"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÏÉ½í¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬$NÉíÉÏµÄ$nÉ¢·¢µÄÁéÆø½«$N°üÎ§¡£\n");
        set("unit","¼ş");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor",6);
        set("armor_prop/dodge",2);
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
