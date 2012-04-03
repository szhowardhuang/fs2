
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","练\功房");
        set ("long","这里是古堡三楼的练功房，两旁的火炬将这里照得耀如白昼，
其中有些妖魔正在练习。招式精妙，威力惊人，拳掌中夹着
呼呼风雷声。你心中一凛，这不是失传已久的风雷八式么？
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" :  __DIR__"room49",
            "west" : __DIR__"room71",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/wind-cloud-ghost" : 4,
      ]));

        setup();
}
