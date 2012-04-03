// ½â¶¾..
inherit F_MEDICINE;

void create()
{
	set_name("È¥´ºÍè",({"cure flower pill","pill"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
  	        set("unit", "ºÐ");
                set("base_unit", "Á£");
                set("base_weight", 100);
		set("value", 500);
		set("cure_type","poison");
		set("cure_poison_type","flower_poison");
		set("medicine_power",1);
	}
	set_amount(1);
	setup();
}
