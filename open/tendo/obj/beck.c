// beck.c 这是我 cp 过来的，内容和原版的一模一样
// cp by borstquc

inherit ITEM;
//inherit F_LIQUID;

void create()
{
        set("no_get", 1);
        set_name("水缸",({"beck"}));
        set("long","一个用来装清水的水缸。\n");
        set("饱和",50);
        set("液体", ([
                "种类": "水",
                "名称": "清水",
                "剩": 50,
                "止渴": 30,
        ]) );
        setup();
}
