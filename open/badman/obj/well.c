inherit ITEM;
//inherit F_LIQUID;

void create()
{
        set("no_get", 1);
        set_name("水井",({"well"}));
        set("long","一个供人取水的地方 .\n");
        set("饱和",50);
        set("液体", ([
                "种类": "水",
                "名称": "清水",
                "剩": 50,
                "止渴": 30,
        ]) );
        setup();
}
