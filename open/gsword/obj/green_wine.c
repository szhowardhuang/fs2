// waterskin.c

inherit ITEM;
//inherit F_LIQUID;

void create()
{
	set_name("竹叶青", ({"green wine","wine","green"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "竹叶青酒装在一个竹筒里，酒性极烈\n");
		set("unit", "筒");
		set("value", 200);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("液体", ([
		"种类": "酒",
		"名称": "竹叶青酒",
		"剩": 20,
		"止渴" : 22,
		"酒精成份": 10,
	]) );
	setup();
}
