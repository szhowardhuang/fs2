// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("青布鞋",({"green boots","boots"}) );
        set_weight(3500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","普通的青布布鞋.\n");
        set("unit","件");
        set("value",250);
	set("material","cloth");
        set("armor_type","boots");
        set("armor_prop/armor", 2);
	}
        setup();
}
