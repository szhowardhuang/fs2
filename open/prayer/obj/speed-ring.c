inherit EQUIP;

void create()
{
        set_name("[36mËÙ¶È½äÖ¸[0m",({"speed ring","ring"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","Î÷ÓòÆÆĞ°¶´¿ßÄÚÌØ²úµÄ±¦Ê¯ËùÖÆ³É£¬´÷ÉÏºó»áÔÚÄãÉí±ß²úÉúÆøÁ÷£¬Ê¹ÄãµÄÒÆ¶¯ËÙ¶È¼Ó¿ì¡£\n");
        set("unit","¼ş");
        set("value", 10000);
        set("material","gem");
        set("no_sell",1);
        set("armor_type","finger");
        set("armor_prop/move",3);
        set("armor_prop/dodge",3);
        set("armor_prop/armor", -5);
        }
        setup();
}        
