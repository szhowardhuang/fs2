// open/killer/ninja/find/rx17.c
// 当玩家发生抉择错误，就会受到严重精神伤害，退回最初点
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "心灵探索");
  set ("long", @LONG
  
  这么有趣的情况，当然要好好的参与一下，你立刻纵身拦下此一队伍。
  然而你立刻发现这是多么愚蠢的一件事情，因为既然人家是在潜行。
  自然不会希望有人视破，就在你想通这一件事的瞬间。
  由此人身上放出排山倒海的剑气，贯穿了你的身体.....
  在你眼前一黑之前听到‘仙剑后九式之......’
  后九式？仙剑怎么会有后九式？.......
   
LONG);
  set("no_transmit",2);
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

