 inherit EQUIP;
void create()
{
        set_name("乾坤护腕",({"boris hands","hands"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
圣火教教主专用的护腕, 能大量提高本身的攻击力与双手的肌力!!
");
        set("unit", "双");
        set("value",100000);
        set("material","leather");
        set("armor_type", "hands");
        set("armor_prop/armor",5);
        set("armor_prop/attack",5);
        }
        setup();
}                    