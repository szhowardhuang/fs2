
inherit EQUIP;

void create()
{
        set_name("紫翠长裙", ({ "blue skirt", "skirt" }) );
        set_weight(4500);
        set("long", "一件织工精细的紫色蝉丝长裙, 上面镶着细细的金线, 显得格外美丽。\n");
        set("unit", "件");
        set("value",5000);
        set("material", "丝质");
        set("armor_type", "pants");
        set("armor_prop/armor", 8);
        setup();
}
