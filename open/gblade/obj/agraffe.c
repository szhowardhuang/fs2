inherit EQUIP;

void create()
{
        set_name("青丝软甲", ({ "agraffe" }) );
        set_weight(3200);
        set("long", "
虽然是用金属丝线打制成的，但是一点也不会影响身体的活动，能提供不
错的保护能力。

\n");
        set("unit", "件");
	 set("value",10000);
        set("material", "steel");
        set("armor_type", "cloth");
	set("armor_prop/armor", 20);
	set("armor_prop/parry",2);
        setup();
}
