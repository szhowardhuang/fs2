// robe by Airke
// QC by Anmy (98/2/25)

inherit EQUIP;

void create()
{
        set_name("µÀÅÛ",({"robe"}));
        set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
                set("value", 800);
		set("material", "cloth");
		set("armor_type", "cloth");
                set("armor_prop/armor",  8);
                set("armor_prop/dodge", 2);
	}
	setup();
}

		
