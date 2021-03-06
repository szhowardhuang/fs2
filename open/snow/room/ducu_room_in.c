#include <room.h>

inherit ROOM;

void create()
{
	set("short","独孤陵灵堂");
          set("long",@LONG
这里就是独孤陵的灵堂，堂上所祭拜的乃是雪苍派第三代掌门独孤愁，外号叫
「九转邪云”，相传在十年前，独孤愁乃是武林四大高手之一，与仙剑派的郑士欣
，魔刀莫测，及儒门第一高手刑千书三人并列，独孤愁以拿手的雪苍鬼影脚及其自
创之黑影迷踪步法，夺得武林「霸王尊”之名。在灵位旁的是独孤愁生前所作的诗
句，诗句上写着：
      
          「江湖几番狂霸中，奈合几回无名”
 
                          「四海何时风云起，怎知独孤无愁”
 
 
LONG);
        set("exits", ([
	"east":__DIR__"ducu_room",
	"west":__DIR__"ducu_room_in1",
	"north":__DIR__"ducu_live",
        ]) );
	set("light_up",1);
        setup();
}
