// beck.c

inherit ITEM;
//inherit F_LIQUID;

void create()
{
	set("no_get", 1);
	set_name("喷水池",({"pool"}));
	set("long","一个优雅别致的喷水池。\n");
	set("饱和",50);
	set("液体", ([
		"种类": "水",
		"名称": "清水",
		"剩": 100000,
		"止渴" : 30,
		"drink_func":0,
	]) );
	setup();
}
