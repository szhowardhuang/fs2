//open/prayer/room/2elder4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "执法长老房");
  set ("long", @LONG

	    前面有一个圣火弟子正在蹲马步，看来又
	是做错了什么小事，而被执法长老处罚，真不
	敢想要是犯了大错会如何．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/2elder3",		//`长老房
	"east" : "/open/prayer/room/2elder7",		//`长老房
]));
  set("light_up", 1);

  setup();
}
 
