// Room: /open/doctor/room/d9.c

inherit ROOM;
int have = 1;
int time = 0;
void create ()
{
  set ("short", "花园");
  set ("long", @LONG
这里是银针门的花园，种满了各地收集来的奇花异草，
只见处处馨香，团花仅簇，但却有那么一点点的奇异，就是
这若大的花园里，竟不见蝶飞蜂舞，似忽有些密秘。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/doctor");

  set("exits", ([ /* sizeof() == 3*/
  "west" : __DIR__"d8",
  "east" : __DIR__"d10",
  "north": __DIR__"d6",
]));
set("objects",([
"/open/gblade/obj/smallstone.c":1,
]));
  setup();
  set_heart_beat(1);
}
void init()
{
    add_action("search_here", "search");
    add_action("pull_it","pull");
} 
int search_here(string arg)
{
    if( (this_player()->query("combat_exp",1) > 10000)  && have)
      write("你找啊找的,终于发现有人用奇门遁甲隐藏了一棵灵芝.\n"+
            "你可以试着拔它(pull it).\n");
    else
      write("也许是你经验不足,你什么也没发现...\n");
    return 1;
}
int pull_it(string arg)
{
    object user,ob;
    user = this_player();
    if( (user->query("combat_exp",1) > 10000)  && have)
    {
    have = 0;
    ob=new("/open/doctor/npc/grass");
    ob->move("/open/doctor/room/d9");
    message_vision("当$N正要拔起灵芝时,只见一只守药邪兽冲了出来!!\n", user);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
time++;
if(time > 300)
{
time = 0;
have = 1;
}
return;
}
