// 钥匙, 有锁的房间请到 /u/w/wade/room/key_room 参考
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIB"蓝钥匙"NOR, ({ "bluekey","key", "blue" }) );
        set("unit", "把");
        set("no_auc",1);
set("no_get",1);
set("no_give",1);
        set("long", "一把看起来普普的钥匙，专门用来开门上的锁用的。\n");
        // 底下这个是设定它可以用的房间
        set ("key_of_room", ({ __DIR__"key_room"}) );

}

