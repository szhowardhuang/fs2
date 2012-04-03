#include <armor.h>
#include <ansi.h>
inherit BOOTS;
object me=this_player();
void create()
{
        set_name(HIY"½£Ê¥Õ½Ñ¥" NOR,({"kensai boots","boots"}) );
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit","Ë«");
                set("value",0);
                set("armor_prop/armor",12);
                set("armor_prop/dodge",10);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);

        set("no_drop",1);
        set("no_get",1);
                set("armor_prop/move",10);
                set("material","steel");
                set("long","´ËĞ¬ÎªÒ»ÖÖ²»ÖªÃûµÄ²ÄÁÏËùÖÆ³É¡£\n");
                set("wear_msg","$N´©ÉÏ$n[1;33m¶ÙÊ±¸Ğµ½ÉíÉÏÖØÁ¿¼õÇáĞí¶à¡£[0m\n");
                setup();
        }
}
