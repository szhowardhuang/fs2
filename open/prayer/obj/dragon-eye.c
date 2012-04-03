//»Æ¼×½ğÁúµÄÑÛÖé()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[33m»Æ¼×½ğÁúµÄÑÛÖé[0m", ({ "dragon eye","eye" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿Å");
          set("long","ÕâÊÇÆÆĞ°¶´¿ßÖĞ[33m»Æ¼×½ğÁú[0mµÄÑÛÖé, ´«ÎÅ[33m»Æ¼×½ğÁú[0mÈ«ÉíÉÏÏÂ¾ù¾ßÓĞÁúµÄÄ§Á¦¡£\n");
          set("value", 800);
          set("material", "gem");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


