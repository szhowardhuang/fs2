inherit ROOM;
#include <ansi.h>
void create () {
        set ("short","天山山脚");
        set ("long",@LONG
你抬头一望，天山山顶直耸云霄，从山腰开始一片的雪白往上延伸。
定神一看似忽在远处有座宏伟的建筑，你的好奇心不断的催促你加快脚步
往前走去
LONG);
           
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"room3",
        "south" :  __DIR__"room1",       
        ]));

       
        setup();
}
