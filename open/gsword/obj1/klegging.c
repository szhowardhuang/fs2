
#include <ansi.h>
#include <armor.h>
inherit LEGGINGS;
object me=this_player();
void create()
{
        set_name(HIY"½£Ê¥»¤Ï¥"NOR,({"kensai legging","legging"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","¼þ");
        set("value",0);
        set("material","blacksteel");
        set("long","²»ÖªÃûµÄ²ÄÖÊ.¼ÓÉÏ´ó½£Ê¦µÄÊÖÒÕ.´Ë·À¾ßÓÐ×Å²»ÖªÃûµÄÉñÁ¦¡£\n");
        set("wear_msg",WHT"´©ÉÏ$n[30mºó£¬¶ÙÊ±·À»¤Ôö¼Ó¡£\n"NOR);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
      this_object()->set("armor_prop/sword",8);
        this_object()->set("armor_prop/armor", 9);
        this_object()->set("armor_prop/move",5);
        this_object()->set("armor_prop/parry",6);
}
