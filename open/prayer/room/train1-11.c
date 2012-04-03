//open/prayer/room/train1-11

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG

	    眼前的圣火教总坛练武场上，你看到许多
	圣火弟子拼命的勤练武功．看来圣火教的早晚
	会进驻中原． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee3" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-16",		//练武场
	"north" : "/open/prayer/room/train1-6",		//`练武场
	"west" : "/open/prayer/room/train1-12",		//`练武场
]));

  setup();
}
 
