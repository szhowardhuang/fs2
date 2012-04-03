// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short", HIG"神秘地带"NOR);
        set ("long","这里似乎就是傲啸天所说的神秘地带，传说由此可以逃到古堡外头，
只见这里泛着淡淡的惨绿，诡异万分，你不禁考虑是否藉机逃到外
头，毕竟这里的妖魔实在太可怕了...念头一转，还是先搜寻(search)
一番再说吧...
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
        "east" :  __DIR__"room31",  
            
            
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

        if(!str || str != "hole"){
                return notify_fail("你想跳到那里？\n");
                           return 1;
                                 }
            me->add("sen",-100);
            tell_object(me,"你纵身跳进这绿色的漩涡，顿时神智昏迷，迷迷糊糊中被传到某一地方.....。\n");
            me->move(__DIR__"entrance");
            return 1;

            
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,"你找啊找，终于在墙上发现一个绿色的漩涡(hole)，怪诡异的，跳(jump)进去不知会到那里？\n");
 return 1;
}
