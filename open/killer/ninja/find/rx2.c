// open/killer/ninja/find/rx2.c
// 当玩家发生抉择错误，就会受到严重精神伤害，退回最初点
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "心灵探索");
  set ("long", @LONG
     你不管柴荣是不是有办法挡下这一招，立刻发出暗器，挡下这一招
     但是没想到在暗器发出的同时，柴荣的身影突然消失，然后出现在你的背后
     
     ‘你到底是谁？你是不是东瀛派来的间谍？!!’
     正当你想回答的时候，刚才那条黑影宛如灵蛇一般，贯穿的了你的身体!!!!
     你的精神受到严重创伤!!神志开始昏迷不清..........

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

