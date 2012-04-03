// room7.c by roger
inherit ROOM;
#include <ansi.h>
void create () {
set ("short", HIR"焚天魔域"NOR);
        set ("long","这个房间一片通红，墙上有团红色的火焰，烈焰奔腾，火焰随着你的情绪起伏有秩。
看起来蛮吓人的，不妨(search)一番看看有啥收获。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
        "north" :  __DIR__"room64",  
            
            
      ]));

        setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_jump","jump");
}

int do_jump(string str){

   object me;
   me = this_player();

        if(!str || str != "fire"){
                return notify_fail("你想跳到那里？\n");
                           return 1;
                                 }
            me->add("sen",-100);
            tell_object(me,"你纵身跳进这红色的火焰，顿时神智昏迷，迷迷糊糊中被传到某一地方.....。\n");
            me->move(__DIR__"entrance");
            return 1;

            
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,"你找啊找，终于在墙上发现一团红色的火焰(fire)，怪诡异的，跳(jump)进去不知会到那里？\n");
 return 1;
}
