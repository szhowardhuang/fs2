#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
       set_name(HIY "½£Ê¥Êø¼×" NOR, ({ "kensai pants" ,"pants" }) );
       set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 0);
                set("long","ÒøÖÆ»¤¾ß...Ö÷ÒªÔÚ´®Á¬½£Ê¥·À¾ßËùÒÅÂ©Ö®²¿·Ö¡£\n");
            set("wear_msg",HIC"´©ÉÏ$n[1;37mºó£¬½£Ê¥Ö®Á¦Ë²¼ä´ÜÆð¡£\n"NOR);
                set("material", "sliver");
                set("armor_prop/armor", 15);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
                set("armor_prop/parry", 10);
                set("armor_prop/sword", 7);
                set("armor_prop/dodge", 10);
        }
                setup();
}
