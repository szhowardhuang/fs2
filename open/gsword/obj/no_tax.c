inherit ITEM;

void create()
{
        set_name("免税金牌", ({ "no_tax" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
set("long","朝庭所颁与可免税的金牌.\n");
                set("value", 10000);
        }
}

