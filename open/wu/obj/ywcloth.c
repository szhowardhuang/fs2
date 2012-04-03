#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
   set_name("[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[1;31m¡õ[1;33m¡õ[0m" ,({"gold cloth","cloth"}));
   set_weight(30000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("unit","¼ş");
   set("value",150000);
   set("material", "cloth");
   set("long",HIW"ÕâÊÇÒ»¼şÓÉ´«ËµÖĞĞşÌìÓñ¼ÓÉÏ½ğïÎÏßËù±à³ÉµÄ±¦ÒÂ¡£\n"NOR);
   set("wear_msg", "$N½«$n´©ÉÏ£¬"HIY"½ğïÎÒÂ"NOR"µÄÁ¦Á¿¹á×¢ÔÚ$NÉíÖĞ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô£¬"HIY"½ğïÎÒÂ"NOR"µÄÁ¦Á¿ËæÖ®ÊÅÈ¥¡£\n");
   set("armor_prop/armor",30);
   set("armor_prop/force",3);
   set("armor_prop/unarme",3);
   set("armor_prop/dodge",-5);
}
        setup();
}
