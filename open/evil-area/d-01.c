inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIC"湖泊"NOR);
        set("long",@LONG
四周已经被湖泊呈凹字形给阻隔住了，除了你来时的路以外，你
眼前的地上放置着一个有凹巢的石块，凹巢内写满了许许多多密密麻
麻的文字，都是你前所未见过的字体，
LONG);
        set("item_desc",([
"石块":"你仔细的注视着石块, 似乎没有什么奇特的。\n",
"凹巢":"凹巢内沾有几滴深蓝色的液体，似乎曾经置放过什么东西。\n",
]));
        set("exits",([
"north":__DIR__"d-02",
]));
        set("objects",([
__DIR__"npc/water-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        set("water-area",1);
        setup();
}

void init()
{
add_action("do_search","search");
add_action("do_move","move");
}

int do_search(string arg)
{
object me=this_player();
        if(!arg || arg!="凹巢")
                return 0;
        tell_object(me,HIY"
你仔细的搜寻着凹巢内部，突然发现了一个奇怪的地方～

        凹巢下似乎有另一个空间，里面不时的传来阵阵风声

        或许你可以将某样液体放置于内。\n"NOR);
        me->set_temp("evil/king/water_search",1);
        return 1;
}

int do_move(string arg)
{
object me,ob;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="石块")
                return 0;
        if(!me->query_temp("evil/king/water_search"))
                return notify_fail("你不晓得该往哪里着手，移动了半天，石块动都不动。\n");
        if(!ob->query_temp("can_move"))
        {
                message_vision("$N使劲了吃奶的力气尝试移动石块，石块却动也不动。\n",me);
                return notify_fail("你累的一直喘～\n");
        }
        message_vision(HIC"由于$N移动着石块，放置于凹巢内的"HIB"水血"HIC"跟随着晃动了起来～

        一瞬间"HIB"水血"HIC"突然暴涨出凹巢，将$N团团包住，吸入凹巢内～\n\n"NOR,me);
        ob->delete_temp("can_move");
        me->delete_temp("evil/king/water_search");
        message_vision("$N从上方的通道掉下来，来到这里。\n",me);
return 1;
}
