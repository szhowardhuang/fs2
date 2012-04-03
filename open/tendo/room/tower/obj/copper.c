//»ÆÍ­
#include <command.h>
inherit ITEM;

void create()
{
        set_name("[1;32m»ÆÍ­[0m", ({ "copper" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "¿é");
          set("long",@LONG
        ÕâÊÇÒ»¿é»ÆÍ­!!»ÆÍ­µÄÎïÀíĞÔÖÊ½ÏÉúÌúÎÈ¶¨, ÊÇ×îÔç±»Ê¹ÓÃ
        µÄ½ğÊô!!Äã¿ÉÒÔ½«Õâ¿é»ÆÍ­ÄÃÈ¥´òÔì³ÉÎäÆ÷»òÊÇ·À¾ß!!²»¹ı
        »ÆÍ­µÄÓ²¶È½ÏÌúĞ¡, ËùÒÔ×ö³ÉµÄÎäÆ÷¿ÉÄÜ»áºÜÈİÒ×¾Í¶ÏµôÁË
        !!
LONG);
          set("value", 800);
          set("material", "copper");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}



