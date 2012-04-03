#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("[32mÇ¬À¤Õ½¶··ş[0m",({"boris-cloth","cloth"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","¼ş");
        set("value", 200000);
        set("armor_type","cloth");
        set("wear_msg","[36m$N´©ÉÏÁË$nÖ®ºó,Ö»¼û[35mØÔÏóÈçºç[36m,È«ÉíÉ¢·¢³öĞÛ»ëµÄ¶·Æø!![0m\n");
        set("remove_msg","$N½«$nÍÑÏÂÖ®ºó,ĞÛ»ëµÄ¶·ÆøÂıÂıµØÏûÉ¢ÁË!!\n");
        set("armor_prop/armor", 20);
        set("armor_prop/dodge", 5);
        set("armor_prop/unarmed", 15);
        set("armor_prop/stick", 15);
        set("armor_prop/force", 5);
        set("long","
Î÷ÓòÌØÊâµÄÖ¯ÁÏÔÙ×ôÒÔÑª÷è÷ëµÄÁÛÆ¤»ìºÏÖÆ³É,Ç°ÃæĞåÓĞÊ¥»ğ½ÌµÄÊ¥»ğ
Í¼Ñù,ºóÃæÔòÊÇÅ®æ´ÄïÄïµÄÍ¼Ïó. µ¶Ç¹²»Èë,Ë®»ğ²»ÇÖ.ÊÇÊ¥»ğ½ÌÀú´ú½ÌÖ÷
µÄµÕ´«±¦ÒÂ¡£\n");
        }
         setup();
}





