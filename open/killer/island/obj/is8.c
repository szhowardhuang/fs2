inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙滩");
  set ("long", @LONG
遍地的白沙, 除了一棵枯树与一块大岩之外, 并没有其他事物. 你虽觉得枯
树与岩石的感觉十分怪异, 但是经过仔细的寻找并没有找到什么奇怪的地方. 此
地除了东边是海之外, 其他方向放眼望去都是白蔼蔼的沙滩, 在西北方能见到一
座高耸的岩壁.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is13.c",
  "west" : __DIR__"is7.c",
  "south" : __DIR__"is5",
]));

  setup();
}
void init()
{
add_action("do_search", "search");
add_action("do_look", "look");
add_action("do_get", "get");
add_action("do_put", "put");
}
int do_search()
{
object me=this_player();
if (me->query_temp("can_search")==1)
{
tell_object(me,HIC"你赫然发现岩石的树旁可以看到因退潮而呈现的沙岸上有一块扁平的大岩石(stone).\n"NOR);
tell_object(me,HIY"原来黎明时是这座岛退潮的时间 .\n"NOR);
new("/u/u/unfinished/room/obj/stone.c")->move(environment(me));
me->delete_temp("can_search");
me->set_temp("can_back",1);
return 1;
}
else
{
return 0;
}
}
int do_look(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
else
{
tell_object(me,"testtest");
return 1;
}
}
int do_get(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="all from box")
       return 0;
   if(me->query_temp("care")==1)
{
tell_object(me,"you are care 2 !!");
me->set_temp("care",2);
return 1;
}
else
{
tell_object(me,"don't get anything !!");
me->set_temp("care",1);
return 1;
}
}
