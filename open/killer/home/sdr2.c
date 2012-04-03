inherit ROOM;

void create ()
{
set("short","杀手地下训练场 A 区");
  set ("long", @LONG
这里是杀手总坛的地下迷宫，也是由机关手诸冈渡所精心设置。
寻常人并无法轻易的离开此处，或许应该小心一点，
因为四周传来的杀气，正诉说着此处所布满的危机。
但是这里也是顶尖杀手自我训练的好地方。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"sdr6.c",
"south" : __DIR__"sdr3.c",
"north" : __DIR__"sdr1.c",
]));
set("objects",([
"/open/killer/npc/sdkilla.c":3,
]));
  setup();
}

void init()
{
 add_action("do_search",({"search"}));
}

int do_search (string arg)
{
 object me,ob;
 
 me=this_player();
 if ( me->query_temp("mission3") != 3)
   return 0;
 if (!arg)
 {
   message_vision("$N仔细的找了一下，发现了一个按钮，按下之后，出现一条往下的通道。\n", me);
   set("exits/down", __DIR__"sdr17.c");
   me->set_temp("mission3",4);
   return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
  if (dir != "down") 
  {
    this_object()->delete("exits/tree");
    return 1;
  }
  if (me->query_temp("mission3") != 4)
    return 0;
  this_object()->delete("exits/tree");  //只可进去一次
  return 1;
}