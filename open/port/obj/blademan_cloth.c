// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("刀者之服",({"blademan cloth","cloth"}));
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","初入江湖之刀客最常用的基本配备 .\n");
        set("unit","件");
	set("value",400);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor",3);
	set("armor_prop/dodge",1);
	}
        setup();
}
