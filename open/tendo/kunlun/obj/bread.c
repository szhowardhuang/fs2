// dumpling.c

inherit ITEM;

void create()
{
	set_name("馒头", ({ "bread" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long", "一个香喷喷、热腾腾的大馒头。\n");
		set("unit", "个");
		set("value", 15);
		set("食物", ([
                        "剩" : 3,       // 可以吃几口
                        "供应": 60,     // 每一口填饱肚子的量
                ]) );
	}
	setup();
}
