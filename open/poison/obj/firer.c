// 钥匙, 有锁的房间请到 /u/w/wade/workroom 参考
inherit ITEM;

void create()
{
        set_name("赤火令", ({ "firer" }) );
        set("unit", "只");
        set("long", "这是一只令牌，上面刻有圣火的图样。\n");
        set_weight(500);
        set("value",0);
}
