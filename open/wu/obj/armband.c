
// sun_armband.c

inherit EQUIP;

void create()
{
        set_name("[0;31m¡õ[1;31m¡õ[0;31m¡õ[1;31m¡õ[0;31m¡õ[1;31mu[0;31m¡õ[1;31m¡õ[0m ",({"Sun Fire Armband","armband"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","ÓÃ³àá×½ğÖÆ³ÉµÄ±Û»·, ÉÏÃæÏâÓĞÒ»¿ÅÑôÑ×Ê¯, Ïà´«Î¨ÓĞÈ­Ê¥²ÅÓĞ×Ê¸ñÅä´÷´Ë±Û»·");
        set("unit","¸ö");
        set("value",1750);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor", 8);
        set("armor_prop/unarmed", 10);
        set("armor_prop/force", 10);
        set("armor_prop/dodge", 10);
        }
        setup();
}
