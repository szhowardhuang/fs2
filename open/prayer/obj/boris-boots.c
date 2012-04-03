inherit EQUIP;

void create()
{
        set_name("[32mÇ¬À¤Õ½¶·Ñ¥[0m",({"boris boots","boots"}) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","[31mÊ¥»ğ½Ì[0m½ÌÖ÷×¨ÓÃµÄÕ½¶·Ñ¥£¬ÒÔ¹ÖÊŞÁÛ¼×¾«Á¶»ìÖ¯¶ø³É¡£\n");
        set("unit","Ë«");
        set("value", 50000);
        set("material","leather");
        set("armor_type","boots");
        set("wear_msg","[36m´©ÉÏ$nÖ®ºó£¬$NµÄÉíÌå¶ÙÊ±ÊÜµ½¾ÅÌìÖ®ÆøµÄÇ£Òı£¬ĞìĞìÉıÆğ¡£[0m\n");
        set("armor_prop/move", 5);
        set("armor_prop/dodge", 5);
        set("armor_prop/armor", 5);
        }
        setup();
}        