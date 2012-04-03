//»Æ¼×½ğÁúµÄ¹Ç÷À()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[33m»Æ¼×½ğÁúµÄ¹Ç÷À[0m", ({ "dragon bone","bone" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¸ù");
          set("long","ÕâÊÇÆÆĞ°¶´¿ßÖĞ[33m»Æ¼×½ğÁú[0mµÄ¹Ç÷À, ´«ÎÅ[33m»Æ¼×½ğÁú[0mÈ«ÉíÉÏÏÂ¾ù¾ßÓĞÁúµÄÄ§Á¦¡£
          Èç¹û½«¹Ç÷ÀÄÃÈ¥×ö³ÉÎäÆ÷, ·À¾ß»òÒÂ·ş!? Õæ²»ÖªµÀ»á±ä³ÉÊ²Ã´Ñù×ÓÒ®??..........\n");
          set("value", 800);
          set("material", "bone");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


