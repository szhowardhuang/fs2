//ÉúÌú
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[1;37mÉúÌú[0m", ({ "iron" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long",@LONG
        ÕâÊÇÒ»¿é¸Õ´Ó¿ÓÖĞÍÚ¾ò³öÀ´µÄÌú¿ó!!Ìú¿óÊÇÖÆ×÷ÎäÆ÷Ê±Ëù±ØĞë
        µÄ²ÄÁÏÖ®Ò», ÒòÎªËüµÄÃÜ¶È¹», Ó²¶È¼Ñ, ÑÓÕ¹ĞÔÒ²ÊÊÖĞ!!ËùÒÔ
        ÊÇÎäÆ÷×î³£¼ûµÄÖ÷Òª²ÄÖÊ!!
LONG);
          set("value", 800);
          set("material", "iron");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}




