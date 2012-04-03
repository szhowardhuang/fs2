//»Æ¼×½ğÁúµÄÆ¤¸ï()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[33m»Æ¼×½ğÁúµÄÆ¤¸ï[0m", ({ "dragon fur","fur" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¼ş");
          set("long","ÕâÊÇÆÆĞ°¶´¿ßÖĞ[33m»Æ¼×½ğÁú[0mµÄÆ¤¸ï, ´«ÎÅ[33m»Æ¼×½ğÁú[0mÈ«ÉíÉÏÏÂ¾ù¾ßÓĞÁúµÄÄ§Á¦¡£
          Ö»Òª½«Õâ¿éÆ¤¸ïÄÃÈ¥×ö³ÉÎäÆ÷»ò·À¾ß!? ÄÇ²»¾Í..........\n");
          set("value", 800);
          set("material", "fur");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


