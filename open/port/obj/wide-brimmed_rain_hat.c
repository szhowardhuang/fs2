// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("斗笠",({"wide-brimmed rain hat","hat"}));
	set_weight(500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","由粗布所制 , 用来遮光挡雨 .\n");
        set("unit","件");
	set("value",100);
	set("material","cloth");
	set("armor_type","head");
	set("armor_prop/armor",1);
	}
        setup();
}
