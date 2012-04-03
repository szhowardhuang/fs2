#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("ÁúÖ®È­·¨ÒÂ",({"dragon-robe","robe"}) );
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","¼ş");
        set("value", 60000);
        set("wear_msg","$N´©ÉÏÁË$nÖ®ºó,ºôµÄÒ»Éù,Õû¸öÈËÈçÍ¬ÊÇ[33m»Æ¼×½ğÁú[0m°ã,ÄÀµØ[33m±©³ö½ğ¹â[0m!!
            Ö»¾õµÃËÆºõ³Ğ¼ÌÁË½ğÁúĞ×ÃÍµÄÁ¦Á¿!!\n");
        set("remove_msg","$N³ıÏÂÁË$nÖ®ºó,ÄÇ½ğ¹â±ãÖğ½¥µØÏûÊ§ÔÚÈ­·¨ÒÂµÄËÄÖÜ......\n");
        set("armor_type","cloth");
        set("armor_prop/armor", 18);
        set("armor_prop/dodge", -3);
        set("armor_prop/unarmed", 10);
        set("armor_prop/stick", 10);
        set("armor_prop/force", 3);
        set("long","
Î÷ÓòÌØÊâµÄÖ¯ÁÏÓë»Æ¼×½ğÁúµÄÁúÆ¤»ìÖ¯¶ø³É,ÒÂ·şµÄÇ°ÃæĞåÓĞÊ¥»ğ½ÌµÄ
Ê¥»ğÍ¼Ñù,ºóÃæÔòÊÇºìÏßËùĞå³öÀ´µÄÁúÌÚ,ÊÇÏóÕ÷Ê¥»ğ½Ì³¤ÀÏÃÇ¸ß¸ßÔÚÉÏ
µÄÈ¨ÊÆ¡£\n");
        }
         setup();
}





