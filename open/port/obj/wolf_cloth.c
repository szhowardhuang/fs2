// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("雪狼衣",({"wolf cloth","cloth"}));
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","由罕见的雪狼皮所制成 , 甚为珍贵 , 穿在身上能大大提高
敏捷度 .\n");
        set("unit","件");
	set("value",5000);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor",10);
	set("armor_prop/dodge",5);
	set("armor_prop/move",3);
	}
        setup();
}
