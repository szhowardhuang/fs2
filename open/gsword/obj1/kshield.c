#include <armor.h>
#include <ansi.h>
inherit SHIELD;
object me=this_player();
void create()
{
        set_name(HIY"Ê¥ÕßÖ®¶Ü"NOR,({"kensai shield","shield"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","ÓÉ´ó½£Ê¦ËùÔìÒÔ²»ÖªÃû²ÄÁÏËùÔìÖ®Ê¥·À¾ß,,¶Ô½£¿ÍÓµÓÐÄªÃûµÄÓ°ÏìÁ¦¡£\n");
        set("wear_msg","[1;32m$N×°±¸ÉÏ$n[1;32mºó£¬¶ÙÊ±¾õµÄÓÐºÜÇ¿µÄ·À»¤Á¦¡£[0m\n");
        set("unit","¼þ");
        set("value",0);
        set("material","blacksteel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
        this_object()->set("armor_prop/sword",8);
        this_object()->set("armor_prop/armor",12);
        this_object()->set("armor_prop/parry",10);
        this_object()->set("armor_prop/force",10);
}
