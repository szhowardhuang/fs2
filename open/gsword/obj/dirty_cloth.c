// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("肮脏衬衫",({"dirty cloth","cloth"}) );
        set_weight(4500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一件很脏的工作衬衫,上面沾满了汗与灰.\n");
        set("unit","件");
        set("value",150);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor", 2);
	}
        setup();
}
