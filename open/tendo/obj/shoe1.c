// shoe.c

inherit EQUIP;

void create()
{
        set_name("µÀÊ¿Ñ¥", ({"shoes"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 400);
                set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 1);
                set("armor_prop/dodge", 1);
        }
        setup();
}

