//open/prayer/room/westarea/road37.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have=1;
int time=0; 
 
void create()
{
        set("short","街道");
        set("long",@LONG

        圣火教南北向的快速道路. 往北边走可以到达圣火教的总坛. 
        四方则到处可见圣火教的各个支门. 南边是与中原武林相通的
        甬道. 浑天心法共有十层, 只有教主本人练到第九层的[ 血穹
        苍 ], 其余的门主中, 只有一位司徒知华练到第八层!!

LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road33",        //街道
        "south":"/open/main/room/maiu-1",               //街道
        "east":__DIR__"road36",         //街道
        "west":__DIR__"road38",         //街道

        ]) );
        set("no_fight", 0);
        
  setup();
}

void init()
{
    add_action("search_here", "search");
    add_action("dig_it","dig");
}

int search_here(string arg)
{
    object who=this_player();
    if( who->query_temp("metal/where",7) )
      write("你在这里的四周敲敲打打的, 终于发现了一处挖掘过的痕迹..\n"+
      "挖挖看 (dig) 吧!! 说不定真能挖出什么东东来耶!!\n");
      else
      write("你在干嘛呀??\n");
    return 1;
}

int dig_it(string arg)
{
    object who,ob;
    who = this_player();
    if( who->query_temp("metal/where",7)  )
    {
    ob=new("/open/prayer/obj/gold");
    have = 0;
    ob->move(who);
    message_vision("[36m一阵挖掘之后, 终于挖出来了一块金矿!![0m\n", who);
    who->delete_temp("metal/where");
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 6000)
 {
   time=0;
   have=1;
  }
  return;
}   
