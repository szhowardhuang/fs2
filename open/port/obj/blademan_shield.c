// kame_suit.c

inherit EQUIP;

void create()
{
    set_name("刀者之盾",({"blademan shield","shield"}));
	set_weight(2000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","初入江湖之刀客最常用的基本配备 .\n");
        set("unit","件");
	set("value",300);
	set("material","steel");
	set("armor_type","shield");
	set("armor_prop/armor",2);
	set("armor_prop/parry",1);
	}
        setup();
}
