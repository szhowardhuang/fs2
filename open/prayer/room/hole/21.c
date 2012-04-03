//open/prayer/room/hole/21.c

#include <room.h>
#include "/open/open.h"
inherit ROOM;
int have = 1;
int time = 0;
 
void create()
{
       set ("short", "囹圄池");
       set ("long", @LONG
	血池之下有着可以站立的石崖，石壁上有着六个不同的铁门!!血
	池中的野兽在那里翻滚，一直想要将你撕裂，牠身上的铁链因为
	牠的挣扎，铿然作响，你的安全问题，越来越危险了.....
LONG);
  	set("exits", ([ /* sizeof() == 1 */
	"up" : __DIR__"20",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
	"/open/prayer/npc/kylin" : 1,
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}

void init()
{
	add_action("search_here", "search");
    	add_action("take_it","take");
}

int search_here(string arg)
{
	if( (this_player()->query("combat_exp",1) > 100000) && have)
   write("你向铁门摸呀摸的, 找到了开关并打了开来, 里面插着一只\n"+
         "发光的白水晶....你决定要将它拿走(take it).\n");
    else
   write("也许是你的技术太差, 找不到铁门的开关...\n");
    return 1;
}
int take_it(string arg)
{
    object user,ob;
    user = this_player();
    if( this_player()->query_temp("can_take") && have)
    {
    ob=new("/open/prayer/obj/crystal1");
    have = 0;
    ob->move(this_player());
    message_vision("当$N将白水晶从石壁中抽出来, 只见血麒麟一阵吼叫!!\n"+
                   "牠似乎很厌恶浑天水晶所发出的压迫感",user);
    user->set("quests/white-crystal",1);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
 time++;
 if( time > 3000)
 {
   time=0;
   have=1;
  }
  return;
}   
