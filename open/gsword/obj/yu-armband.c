// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("寒玉护臂",({"yu armband","armband"}) );
        set_weight(12000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","用西域上等寒玉制成的护臂,上面有美丽的花纹\n");
        set("unit","副");
        set("value", 200000);
        set("material","steel");
        set("armor_type","armbands");
	set("armor_prop/armor", 7);
	}
        setup();
}
