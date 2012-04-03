//°×Òø
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[1;37m°×Òø[0m", ({ "silver" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long",@LONG
        ÕâÊÇÒ»¿é°×Òø!!´¿¶ÈÆÄ¸ß!!°×ÒøÊÇÒ»¹óÖØµÄ½ğÊô, ¿ÉÊÇ°²
        ¶¨ĞÔÈ´²»ÊÇºÜºÃ, Ó²¶ÈÒ²ÊÇ²îÇ¿ÈËÒâ, ²»¹ıÃÜ¶È¸ß, ¿ÉÒÔ
        ÓĞĞ§µØ·ÀÖ¹ÎäÆ÷µÄ¹¥»÷ÒÔ¼°¼õµÍÉËº¦Á¦!!
LONG);
          set("value", 800);
          set("material", "silver");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}



