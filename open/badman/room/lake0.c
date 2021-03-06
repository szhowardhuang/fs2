// Room: /open/badman/room/lake0.c
// written by powell 96.4.26@FS

#include <ansi.h>
#include </open/open.h>

inherit ROOM;

void create ()
{
  set ("short", "恶人湖");
  set ("long", @LONG
当你一靠近这个神秘的湖泊，一股寒意立即涌上你心头，这里
虽名为恶人湖，可却没有恶人谷的那份邪恶之气，反倒是令你感到
有股神圣不可侵犯的感觉，不管你是恶人与否，善恶到头终有报的
道理是不能不晓得地!

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"forest16.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "lake" : "一个清澈的湖泊，也许你想潜(dive)下去瞧瞧。\n",
]));
  set("outdoors", "/open/badman");
  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}

    void init()
{
// 先关掉, 以后要写任务时再开
//	add_action("do_pray","pray");
	add_action("do_dive","dive");
}

int do_pray()
{
	object who;
	who = this_player();
	if (who->query_temp("pray_god") == 1) 
	tell_object(who,"\n你闭上眼睛，开始祈祷........\n"+
		       	  "............................\n"+
                          "你的内心如湖水一般地平静，结果甚么事也没发生。\n");
	else {
	tell_object(who,"\n突然，你发现恶人湖的湖水如沸腾般地开始冒出气泡来！\n
                         \n\n然后，你眼前金光一闪，亮的让你睁不开眼睛....\n
                 "HIY"\n█████████████████████████\n
                 "CYN"\r     水神慈祥的对你说道：\n
                      \r     有需要我帮忙的地方吗?\n
                 "HIY"\r█████████████████████████\n
                 "NOR"         
                 \n");
	new(BAD_NPC"watergod.c")->move(this_object());
	who->set_temp("pray_god",1);
	}
	return 1;
}

int do_dive()
{
	object who;
        who = this_player();
        tell_object(who,"\n你深吸一口气，跳进湖中，向湖底潜了下去。\n\n");
	who->move(__DIR__"lake1");
	return 1;
}

