#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;
object me=this_player();
void create()
{
        set_name("[1;33m½£Ê¥ÊÖ¼×[0m",({"kensai armband","armband"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼þ");
        set("value",0);
        set("long","²»ÖªÃûµÄ²ÄÖÊÖÆ³É..ËÆºõ×¨Îª½£¿ÍËù×ö¡£\n");
set("wear_msg","$N´©ÉÏ$nºó£¬$n[1;36mÉ¢·¢³öµ­µ«À¶¹â¡£\n");
        set("material","steel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);

        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
this_object()->set("armor_prop/sword",5);
this_object()->set("armor_prop/armor", 10);
this_object()->set("armor_prop/parry", 5);
this_object()->set("armor_prop/dodge", 5);
}
