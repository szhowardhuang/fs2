inherit EQUIP;

void create()
{
        set_name("金丝战袍",({"gold robe","robe"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
由纤细的金丝与柔软的天蚕丝交织而成，是一件兼具防护与轻柔的绝佳战
袍，金碧辉煌的外观，更令人为之炫然三尺。
\n");
        set("unit", "套");
        set("value",10000);
        set("material","crimsonsteel");
        set("armor_type", "cloth");
	set("armor_prop/armor",15);
	set("armor_prop/dodge", 5);
        }
        setup();
}
