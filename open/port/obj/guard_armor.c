inherit EQUIP;
void create()
{
	set_name("守卫队战铠",({"guard armor","armor"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以一片片小钢片串接而成 , 穿在身上 , 甚具防护功效 , 
却因此而引响了活动力 , 是枫林港守卫特有的防具 .
");
        set("unit", "套");
	set("value",1500);
        set("material","steel");
	set("armor_type","cloth");
        set("armor_prop/armor",10);
        set("armor_prop/dodge", -1);
        }
        setup();
}
