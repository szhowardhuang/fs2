//»Æ¼×½ğÁúµÄÁÛÆ¬()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[33m»Æ¼×½ğÁúµÄÁÛÆ¬[0m", ({ "dragon skin","skin" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long","ÕâÊÇÆÆĞ°¶´¿ßÖĞ[33m»Æ¼×½ğÁú[0mµÄÁÛÆ¬, ´«ÎÅ[33m»Æ¼×½ğÁú[0mÈ«ÉíÉÏÏÂ¾ù¾ßÓĞÁúµÄÄ§Á¦¡£
          Èç¹û½«ÁÛÆ¬ÄÃÈ¥×ö³É·À¾ß»òÒÂ·ş!? ÄÇ²»¾Í¿ÉÒÔµ¶Ç¹²»ÈëÁËÂğ??..........\n");
          set("value", 800);
          set("material", "fur");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


