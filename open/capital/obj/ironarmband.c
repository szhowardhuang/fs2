
inherit EQUIP;
							
void create()
{
        set_name("Ìú±Û»·",({"iron armband","armband"}) );
	set_weight(5000);
	set("gender_only", "ÄÐÐÔ");
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","¡£\n");
	set("unit", "Ö»");
	set("value",500);
	set("material","iron");
	set("armor_type", "armbands");
        set("armor_prop/armor",2 );
	}
        setup();
}
