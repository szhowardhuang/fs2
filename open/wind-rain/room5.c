// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","醉星楼");
set ("long", @LONG
    酒楼里挤满了人，这里不但可以看到富贾权贵，风流文士，更可看
到江湖侠客，失意落魄之人。有道楼梯通往楼上雅座，墙上题有一首诗：

               飒 飒 东 风 细 雨 来，芙 蓉 塘 外 有 轻 雷。

               金 蟾 齧 锁 烧 香 入，玉 虎 牵 丝 汲 井 回。

               贾 氏 窥 帘 韩 掾 少，宓 妃 留 枕 魏 王 才。

               春 心 莫 共 花 争 发，一 寸 相 思 一 寸 灰。
LONG);



  set("exits", ([
            "out"  : __DIR__"room4",
            "up"  : __DIR__"room6",
                ]));

       

        setup();
}
