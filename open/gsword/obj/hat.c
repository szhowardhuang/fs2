// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("¹ÏÆ¤Ð¡Ã±",({"little hat","hat"}) );
        set_weight(2500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","Ò»¶¥¹ÏÆ¤Ð¡Ã±.\n");
        set("unit","¼þ");
        set("value", 350);
        set("material","cloth");
        set("armor_type","head");
	set("armor_prop/armor", 3);
	}
        setup();
}
