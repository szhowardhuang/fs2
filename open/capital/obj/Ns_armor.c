// kame_suit.c

inherit EQUIP;
			
void create()
{
        set_name("白翎战甲",({"soldier armor","armor"}) );
	set_weight(20000);
	set("gender_only", "男性");
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","禁卫军所用的战甲，看起来很笨重，但似乎有蛮好的保护。\n");
		set("unit", "套");
	set("value",3000);
	set("material","steel");
	set("armor_type", "cloth");
        set("armor_prop/armor",10 );
	}
        setup();
}
