
inherit ITEM;

void create()
{
	set_name("人肉叉烧包", ({ "dumpling" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个颇大的包子, 听说肉馅是用人肉做的.\n");
		set("unit", "个");
		set("value", 30);
		set("食物", ([
                        "剩" : 5,       // 可以吃几口
                        "供应": 70,     // 每一口填饱肚子的量
                ]) );
	}
	setup();
}
