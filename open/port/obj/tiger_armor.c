inherit EQUIP;
void create()
{
	set_name("白虎之铠",({"tiger armor","armor"}));
	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以上等精钢镶在白虎皮上 , 不但具有强大的防护能力
又弥补了厚重不便的缺点 , 为非常良好之铠甲 .
");
        set("unit", "套");
	set("value",15000);
        set("material","steel");
	set("armor_type", "cloth");
	set("armor_prop/armor",20);
        }
        setup();
}
