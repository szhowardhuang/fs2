// hat by Airke
// QC by Anmy (98/2/25)

inherit EQUIP;

void create()
{
	set_name("ÈýÇåÉñ¹Ú", ({ "trimystic hat", "hat" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¶¥");
		set("value", 100);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 7);
	}
	setup();
}

