// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("木制手环",({"wood wrists","wrists"}) );
        set_weight(4500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","木制的手工木环,可以提供些许的保护.\n");
        set("unit","件");
        set("value", 250);
        set("material","wood");
        set("armor_type","wrists");
	set("armor_prop/armor", 2);
	}
        setup();
}
