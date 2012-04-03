// cloudy-shoes by Airke
// QC by Anmy (98/2/25)

inherit EQUIP;

void create()
{
	set_name("ÆßÐÇ·­ÔÆÑ¥", ({ "cloudy shoes", "shoes" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ë«");
		set("value", 600);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 2);
		set("armor_prop/dodge", 8);
	}
	setup();
}
	
