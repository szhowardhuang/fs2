//»Æ½ğ
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[1;33m½ğ×Ó[0m", ({ "golden" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long",@LONG
        ÕâÊÇÒ»¿é»Æ³Î³ÎµÄ»Æ½ğ!!´¿¶È¿ÉÄÜÓĞ 9999 °É!!Äã¿ÉÒÔ½«Ëü
        ÄÃÈ¥¸øÒ±ÖıµÄ¹¤½³, ½ğ×Ó×ö³ÉÎäÆ÷»òÊÇ·À¾ß¶¼ÊÇ²»´íµÄ!!Ëä
        È»ÃÜ¶È¸ß, °²¶¨ĞÔ¼Ñ, ¿ÉÊÇÓ²¶È²î, ÑÓÕ¹ĞÔ¼Ñ, ×öÎªÎäÆ÷µÄ
        »ù²Ä»áÊ¹µÃÎäÆ÷µÄÊÙÃü¼õ¶ÌĞí¶à!!
LONG);
          set("value", 800);
          set("material", "gold");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}



