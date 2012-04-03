inherit EQUIP;

void create()
{
        set_name("÷ÈÓ°ÉñÑ¥", ({ "boots" ,"black boots" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 3000);
                set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/dodge",2);
                set("armor_prop/move",2);
                set("armor_prop/armor",5);
set("armor_prop/dodge", 1);
        }
}
