#include <room.h>
#include <ansi.h>
inherit ROOM;
string str;

void create ()
{
   set ("short","幸运之间");
   set ("long", @LONG
	度过一次又一次的相同景色后，终于来到有点不一样的地方了。
	但是，这里居然没有任何特殊的事物，也没有守关的敌人。
	在你眼前的只有四个方向，不过这里似乎没有被封印起来。
	难不成可以叫卖东西？看来可以补充一下装备了！
	但是，你终究必须选择一个方向前去。。。。。
 	   (请打move east,north,south,west任一方向)
	
LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  setup();
}

void init()
{//设定这一次的正确方向
  int i;

  i=random(4);
  
  switch(i)
  {
	case 0: str="north";
		break;
	case 1: str="east";
		break;
	case 2: str="west";
		break;
	case 3: str="south";
		break;
  }
  add_action("do_move", "move");
}

int do_move(string arg)
{
  int way;
  object me=this_player();

  if (!arg)
     return notify_fail("选择一个你要去的方向吧。\n");

  if (arg != str)
  {
    message_vision("$N感到一阵眼花撩乱，看来是走错方向了！\n", me);
    me->set_temp("killrun",0);
    me->move(__DIR__"flowrm1.c");
    return 1;
  }
  message_vision(HIW"一道光芒射向$N，一道黑气由$N身上离去了，看来他的罪业消失了！\n"NOR, me);
  me->delete("title");
  me->delete("killyar");
  me->move("/open/killer/room/masterm.c");
  me->save();
  return 1;
}
