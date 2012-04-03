
inherit EQUIP;
													
void create()
{
	set_name("ºìË¿³ñ¶Ð³¤ÅÛ", ({ "red silkcloth", "cloth" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("armor_type", "cloth");
		set("value", 500);
		set("armor_prop/armor", 1);
	}
}
									