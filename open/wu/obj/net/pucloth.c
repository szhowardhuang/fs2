#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
set_name("[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37m¡õ[1;33m¡õ[1;37mP[1;33m¡õ[1;37mn[0m",({"purple cloth","cloth"}));
   if( clonep() )
        set_default_object(__FILE__);
   else {
         set("armor_prop/dodge",10);
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
   set("unit","¼ş");
   set("value",150000);
   set("material", "cloth");
   set("long","ÕâÊÇÒ»¼şÓÉÌìÉÏÖîÉñ²É¼¯ÏÈÌìÁéÆøËùÁ¶Ôì¶ø³ÉµÄÏÉÒÂ¡£\n");
   set("unequip_msg", "$N½«$nÍÑµô,$NÉíÉÏµÄ$nËùÉ¢·¢µÄÁéÆøËæÖ®ÊÅÈ¥¡£\n");
   set("wear_msg", "$N½«$n´©ÉÏ£¬$NÉíÉÏµÄ$nÉ¢·¢µÄÁéÆø½«$N°üÎ§¡£\n");
   set("armor_prop/armor",22);
}
        setup();
}
int query_autoload()
{
 return 1;
}
