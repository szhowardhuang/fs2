// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("白色小衫",({"white suit","suit"}) );
        set_weight(4500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一件白色的普通长衫,看起来像是地摊货.\n");
        set("unit","件");
        set("value",350);
	set("material","cloth");
        set("armor_type","cloth");
        set("armor_prop/armor", 4);
        set("armor_prop/dodge", 1);
	}
        setup();
}
