
#include <ansi.h>
#include <armor.h>
inherit NECK;
object me=this_player();
void create()
{
     set_name(HIY"½£Ê¥¾±ÊÎ"NOR , ({"kensai neck","neck"}) );
     set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "Ìõ");
            set("value", 0);
            set("material","gem");
            set("long","¾±ÊÎÉÏ¸½ÓÐÒ»¿ÅÉÁÉÁ·¢ÁÁµÄ±¦Ê¯..ÒþÔ¼Í¸Â¶³öÎÞ±ÈÕýÆø¡£\n");
set("wear_msg",BLU"´÷ÉÏ$n[34mºó£¬$NµÄÁ¦Á¿Ôö¼ÓÁËÐ©Ðí¡£\n"NOR);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
     }
            setup();
         this_object()->set("armor_prop/sword",5);
            this_object()->set("armor_prop/parry",4);
            this_object()->set("armor_prop/attack",5);
            this_object()->set("armor_prop/armor",9);
}
