// open/killer/ninja/find/rx5.c
// 当玩家发生抉择错误，就会受到严重精神伤害，退回最初点
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "心灵探索");
  set ("long", @LONG
	鸡婆的你，决定出面当个和事老，看看顺便有没有油水可以捞？!
	想不到你的身影才刚刚出现在两人面前的时候，那道黑影穿过你的身体!!
	而且柴荣也一掌将你击飞：‘卑鄙小人，居然敢探查秘密？!’
	精神体在溃散中的你，怎么也想不到，这两人居然这么凶暴？........

LONG);
  setup();
}

void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  call_out("greeting",3 , ob);   
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",7);
     ob->set("sen",1);
     ob->set("gin",1);
     tell_object(ob," 你感到精神逐渐涣散....逐渐陷入昏迷状态..... \n");
     ob->move("/open/killer/room/pillrm.c");
    }
    // 基本上是很不合理啦，就当成巫师测试用，一到最初点
    else 
     ob->move(__DIR__"r1.c");
}

