//´äÓñ
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[1;32m´äÓñ[0m", ({ "gem" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long",@LONG
        ÕâÊÇÒ»¿éÂÌ³Î³ÎµÄ´äÓñ!!Äã¿ÉÒÔ½«ËüÄÃÈ¥¸øÒ±ÖıµÄ´óÊ¦, 
        ´äÓñ×ö³ÉµÄÎäÆ÷»òÊÇ·À¾ß¶¼ÊÇ²»´íµÄ!!
LONG);
          set("value", 800);
          set("material", "gem");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}



