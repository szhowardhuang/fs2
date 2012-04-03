//»Æ¼×½ğÁúµÄÈñ³İ()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[33m»Æ¼×½ğÁúµÄÈñ³İ[0m", ({ "dragon tooth","tooth" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÆÆĞ°¶´¿ßÖĞ[33m»Æ¼×½ğÁú[0mµÄÑÀ³İ, ´«ÎÅ[33m»Æ¼×½ğÁú[0mÈ«ÉíÉÏÏÂ¾ù¾ßÓĞÁúµÄÄ§Á¦¡£
          Èç¹û½«ÑÀ³İÄÃÈ¥×ö³ÉÎäÆ÷!? ÄÇ²»¾Í..........\n");
          set("value", 800);
          set("material", "bone");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


