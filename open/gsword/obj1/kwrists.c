               
#include <ansi.h>
#include <armor.h>
inherit WRISTS;
object me=this_player();
void create()
{
     set_name(HIY"½£Ê¥ÊÖÁ´"NOR , ({"kensai wrists","wrists"}) );
     set_weight(2000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "´®");
            set("value", 0);
            set("material", "crimsonsteel");
            set("long","½£Ê¦ÁúÌúÐÄÒÔ²»ÖªÃû½ðÊôËù´òÔì...¡£\n");
        set("no_auc",1);
        set("no_give",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
            set("wear_msg",CYN"$N°Ñ$n[36m´øÔÚÊÖÉÏ£¬ÉñÊ¥Ö®ÆøÁýÕÖÈ«Éí¡£\n"NOR);
     }
            setup();
         this_object()->set("armor_prop/sword",5);
            this_object()->set("armor_prop/dodge",5);
            this_object()->set("armor_prop/parry",10);
            this_object()->set("armor_prop/armor",10);
}
