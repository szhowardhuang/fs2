// Room: /u/d/dhk/questsfan/room22
inherit ROOM;
#include <ansi.h>
#include <room.h>
#include </open/open.h>

void create ()
{
  set ("short", "晶谷谷底");
  set ("long", @LONG
此地就是传闻中的晶谷第三关，地处晶谷谷底。你望
眼所及，在右手方约十步之遥有一处凉亭，亭内有一绝色
女子双眼微合，似在思索什么。忽然你的脚陷入一条凹沟
中，差点把你拌倒。你仔细一瞧，吓然发现此地纵横交错
数条凹沟。忽然你心念一动施展上成轻功往上一跃。差点
没把你吓死。原然来你所站之处，竟是一幅超大的棋盘，
难到那美人是在下棋，那和谁下呢？又如何推动上百斤的
巨棋呢？

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room23",
  "westup" : __DIR__"room21",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yun.c" : 1,
]));
  set("outdoors", "/u/d");
set("no_transmit", 1);
  setup();
}
int valid_leave(object who,string dir){
if(who->query("marks/fan-finger")!=1)
   if(dir=="east" && who->query("questsfan/quest_step")!=5)
     {
     message_vision(HIC"寒芸柔声的对$N说道:晶谷不是让人随意进入的地方?请阁下快快离去!!\n"NOR,who);
       return notify_fail("寒芸柔声的对你说道:晶谷不是让人随意进入的地方?请阁下快快离去!!\n");
     }
   return :: valid_leave(who,dir);
}
