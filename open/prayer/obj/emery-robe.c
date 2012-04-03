#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("½ğ¸ÕÈ­·¨ÒÂ",({"emery-robe","robe"}) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","¼ş");
        set("value", 10000);
        set("armor_type","cloth");
        set("wear_msg","$N´©ÉÏÁË$nÖ®ºó,Õû¸öÈË¾ÍÏñÊÇ±»[30mÊŞ»ê¸½Éí[0mÒ»Ñù,¼¡Èâ±©ÕÇ,Óë¹ÖÊŞÎŞÒì....\n");
        set("remove_msg","$N³ıÏÂÁË$nÖ®ºó,È«Éí¾­ÂöÎ®ÃÒ²»Õñ,ÃæÉ«²Ô°×......\n");
        set("armor_prop/armor", 17);
        set("armor_prop/dodge", 1);
        set("armor_prop/force", 1);
        set("long","
Î÷ÓòÌØÊâµÄÖ¯ÁÏ¼ÓÉÏ½ğ¸ÕÉ°ËùÖÆ³É.ÒÂ·şµÄÇ°ÃæĞåÓĞÊ¥»ğ½ÌµÄÊ¥»ğÍ¼Ñù,
ºóÃæÔòÊÇÀ¶ÏßËùĞå³öÀ´µÄ½ğ¸ÕÍ¼Ñù,Æ½³£¶¼ÊÇ´©ÔÚÊ¥»ğ½Ì¸÷Ö§ÃÅµÄÃÅÖ÷
¼¶ÈËÎïÉíÉÏ¡£\n");
        }
         setup();
}





