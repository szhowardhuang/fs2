inherit EQUIP;

void create()
{
        set_name("新郎燕尾服", ({ "wedding swallowtail", "swallowtail"  }) );
        set("unit", "件");
        set("long", "一件高级新郎燕尾服，通常都是结婚的时候穿.\n");
	set("gender_only", "男性");
	set("armor_type", "cloth");
	set("armor_prop/armor", 18 );
	set("material", "布料");
	set_weight(3200);
	set("value",4500);
	setup();
}
