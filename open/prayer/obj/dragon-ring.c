inherit EQUIP;

void create()
{
        set_name("[33mÁú¾¦±¦½ä[0m",({"dragon_eye ring","ring"}) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","ÔÚ½äÖ¸µÄÖĞÑëÏâÉÏÎ÷ÓòÆÆĞ°¶´¿ßÄÚ»Æ¼×½ğÁúµÄÑÛÖé¡£\n");
        set("unit","¼ş");
        set("value", 40000);
        set("material","gem");
        set("no_auc",1);
        set("no_give",1);
        set("armor_type","finger");
        set("wear_msg","´÷ÉÏ$nÖ®ºó£¬$NµÄÉíÉÏ¿ªÊ¼²úÉú[33m½ğÁúµÄ¶·Æø¡£[0m\n");
        set("armor_prop/move", -3);
        set("armor_prop/dodge", -3);
        set("armor_prop/armor", 10);
        }
        setup();
}        
