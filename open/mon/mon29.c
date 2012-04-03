inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "山中小穴");
        set ("long", @LONG
通道的尽头，你来到了一处洞中小穴，但是却看不到什么猛兽在
这里，但是依然可以听到阵阵怪兽的嘶吼声，不禁让你想要在这边寻
找一番，也许能够再找到另外一条出路。
LONG);
        set("item_desc", ([ /* sizeof() == 1 */
        "button" : "这是一个暗藏在洞壁中的机关，你可以试着推(push)它。\n",
]));
        set("exits", ([ /* sizeof() == 4 */
        "south"      : __DIR__"mon53",

]));
        setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_push","push");
}
int do_search(string arg)
{
        object me=this_player();

        if(me->query_temp("mon/hole-search"))
        return 0;

        else{
        tell_object(me,"经过一番的搜寻，你在洞的一方发现了一个机关(button)。\n");
        me->set_temp("mon/hole-search",1);
        return 1;
        }
}
int do_push(string str)
{
        object me;
        me = this_player();
        if(me->query_temp("mon/hole-search")!=1)
        return 0;

        if(!str || str != "button")
        return notify_fail("你想推什么？\n");
        else if(!query_temp("have_turn"))
        {
        message_vision("$N轻轻的把机关往前推送。\n",me);
        tell_room(this_object(),"你发现前方的山壁有一道门缓缓的打开。\n");
        set("exits/enter",__DIR__"mon30");
        set_temp("have_turn",1);
        me->delete_temp("mon/hole-search");
        remove_call_out("do_closed");
        call_out("do_closed",20);
        return 1;
        }
        
}

void do_closed()
{
        delete_temp("have_turn");
        delete("exits/enter");
        tell_room(this_object(),"机关感受不到压力，石壁的门竟缓缓地自动关了起来。\n");
}


