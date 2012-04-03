// Room: /open/prayer/room/tanshu/12.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG

    这里是天枢门的练武场,最基层的门生都聚集在这习武,或许你可
以和他们切搓武艺,往北走就是天枢门的门门口. 

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"21.c",
	"south":__DIR__"2-door",
  "north" : __DIR__"11.c",
  "east" : __DIR__"22.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
#include <room.h>
#include "/open/open.h"
  "/open/prayer/npc/trainee4" : 2,
]));
	set("no_clean_up", 0);
        create_door("south","圣火刻纹精钢大门", "north",DOOR_CLOSED);


	setup();
	}
